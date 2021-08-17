#include "fast_pca.h"
#include <iostream>

int main(int argc, char* argv[]) {

    Eigen::MatrixXf data = read_csv("../data/data.csv");

    std::cout << "Performing PCA..." << std::endl;
   
    Eigen::MatrixXf pca = fast_PCA(data);

    std::cout << pca << std::endl;

    return 0;
}
