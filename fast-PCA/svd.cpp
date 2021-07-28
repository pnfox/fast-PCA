#include "fast_pca.h"
#include <iostream>

int main(int argc, char* argv[]) {

    // Select a device and display arrayfire info
    af::setDevice(0);

    std::vector<double> data = read_csv("data.csv");

    std::cout << "data: ";
    for(double n : data){
        std::cout << n << " ";
    }
    std::cout << std::endl;

    //std::cout << "Data: " << data << std::endl;


    std::cout << "Performing PCA..." << std::endl;
    af::array pca = fast_PCA();
    af_print(pca);

    return 0;
}
