#ifndef _FAST_PCA_H_
#define _FAST_PCA_H_
#include <Eigen/Dense>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>



// Unfortunately templated Eigen functions need to be in the header
template <typename Derived>
Eigen::MatrixXf fast_PCA(Eigen::MatrixBase<Derived>& x){
    try {
        Eigen::VectorXf m = x.colwise().mean();
        x.rowwise() -= m.transpose();

        Eigen::BDCSVD<Eigen::MatrixXf> svd;

        if(x.rows() > x.cols()){
            svd.compute(x, Eigen::ComputeThinV);
        } else{
            svd.compute(x, Eigen::ComputeFullV);
        }

        Eigen::VectorXf s_vec = svd.singularValues();
        Eigen::MatrixXf s_mat = s_vec.asDiagonal();
        

//        Eigen::MatrixXf pca = svd.matrixU() * s_mat;
        Eigen::MatrixXf pca = x * svd.matrixV();

        return pca;

    } catch (std::exception &e) {
        fprintf(stderr, "%s\n", e.what());
        throw;
    }
}

Eigen::MatrixXf read_csv(std::string file_name);

#endif
