#include "fast_pca.h"
#include <iostream>

int main(int argc, char* argv[]) {

    // Select a device and display arrayfire info
    af::setDevice(0);

    af::array data = read_csv("../data/data.csv");

    std::cout << "Performing PCA..." << std::endl;
    af::array pca = fast_PCA(data);

    af_print(pca);

    return 0;
}
