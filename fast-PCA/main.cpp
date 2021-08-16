#include "fast_pca.h"
#include <iostream>

int main(int argc, char* argv[]) {

    // Select a device and display arrayfire info
    af::setDevice(0);

    Eigen::MatrixXf data = read_csv_eigen("../data/data.csv");
    std::cout << data.rows() << ", " << data.cols() << std::endl;

    std::cout << "Performing PCA..." << std::endl;
    Eigen::MatrixXf data2(2,3);
    data2 << 3, 3, 3, 6, 6, 6;
    std::cout << data2 << std::endl;
    
    Eigen::VectorXf m = data2.colwise().mean();
    std::cout << m << std::endl;
    std::cout << m.rows() << ", " << m.cols() << std::endl;
    data2.rowwise() -= m.transpose();

    Eigen::MatrixXf pca = fast_PCA_eigen(data2);
    std::cout << pca << std::endl;


    return 0;
}
