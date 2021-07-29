#ifndef _FAST_PCA_H_
#define _FAST_PCA_H_
#include <arrayfire.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>



af::array fast_PCA(af::array x);

af::array read_csv(std::string file_name);

#endif
