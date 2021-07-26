#include "fast-PCA.h"
#include <iostream>

int main(int argc, char* argv[]) {

    // Select a device and display arrayfire info
    af::setDevice(0);

    std::cout << "Performing PCA..." << std::endl;
    af::array pca = fast_PCA();
    af_print(pca);

    return 0;
}
