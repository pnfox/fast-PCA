#include "fast_pca.h"

af::array fast_PCA()
{
    try {
        af::array x = af::randn(20, 5, f32);

        af::array m = af::mean(x);
        m = af::tile(m, x.dims()[0]);
        af::array b = x - m;

        af::array u;
        af::array s_vec;
        af::array vt;
        af::svd(u, s_vec, vt, b);
        af::array s_mat    = diag(s_vec, 0, false);

        // flip signs
        u = u * (u / sqrt(u*u));
        vt = vt * (vt / sqrt(vt*vt));

        af::array pca = af::matmul(u(af::span, af::seq(5)), s_mat);
        return pca;

    } catch (af::exception& e) {
        fprintf(stderr, "%s\n", e.what());
        throw;
    }
}

af::array read_csv(const char* file_name)
{
    std::fstream file(file_name);
    long n_chars = 0;
    std::string line;
    int n_delim;
    int delim_pos;
    int last_delim_pos;
    int row_number = 0;
    int column_number = 0;
    double tmp_data;

    // Find the number of columns in csv file
    std::getline(file, line);
    n_delim = std::count(line.begin(), line.end(), ',');
    column_number = n_delim + 1;

    // Create MxN Arrayfire Array for storing csv
    row_number = std::count(std::istreambuf_iterator<char>(file),
             std::istreambuf_iterator<char>(), '\n') + 1;
    af::array data(row_number, column_number, f64);

    // Find the number of characters in file
	file.seekg(0, std::ios_base::beg);
    if(file.is_open()){
        file.seekg(0, std::ios_base::end);
        n_chars = file.tellg();
    }
	file.seekg(0, std::ios_base::beg);

    // store first line of file as string
    row_number = 0;
    while(std::getline(file, line)){

        auto start_of_search = line.begin();
        auto delim_found = std::find(start_of_search, line.end(), ',');
        delim_pos = delim_found - line.begin();
        last_delim_pos = 0;
        tmp_data = 0;

        for(int i=0; i < n_delim+1; i++){
            tmp_data = std::stod(line.substr(last_delim_pos, delim_pos-last_delim_pos));
            data(row_number, i) = tmp_data;

            // find next delimiter on line
            last_delim_pos = delim_pos+1;
            start_of_search = line.begin() + last_delim_pos;
            delim_found = std::find(start_of_search, line.end(), ',');
            delim_pos = delim_found - line.begin();
        }
        row_number++;
    }

    return data;
}
