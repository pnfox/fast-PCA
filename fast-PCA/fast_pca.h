#ifndef _FAST_PCA_H_
#define _FAST_PCA_H_
#include <arrayfire.h>
#include <Eigen/Dense>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>



af::array fast_PCA(af::array x);

template <typename Derived>
Eigen::MatrixXf fast_PCA_eigen(const Eigen::MatrixBase<Derived>& x);

af::array read_csv(std::string file_name);
Eigen::MatrixXf read_csv_eigen(std::string file_name);

#endif
