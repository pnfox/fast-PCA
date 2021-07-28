#ifndef _FAST_PCA_H_
#define _FAST_PCA_H_
#include <arrayfire.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


af::array fast_PCA();

std::vector<double> read_csv(const char*);

#endif
