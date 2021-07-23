/*******************************************************
 * Copyright (c) 2014, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#include <arrayfire.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace af;

void fast_PCA()
{
    try {
        array x = randn(20, 5, f32);               // copy host data to device
        af_print(x);

        array m = mean(x);
        m = tile(m, x.dims()[0]);
        array b = x - m;

        array u;
        array s_vec;
        array vt;
        svd(u, s_vec, vt, b);
        array s_mat    = diag(s_vec, 0, false);

        // flip signs
        u = u * (u / sqrt(u*u));
        vt = vt * (vt / sqrt(vt*vt));

        std::cout << "Performing PCA..." << std::endl;
        af_print(u);
        af_print(s_mat);
        af_print(vt);
        af_print(u(span, seq(5)));
        array pca = matmul(u(span, seq(5)), s_mat);
        af_print(pca);

    } catch (af::exception& e) {
        fprintf(stderr, "%s\n", e.what());
        throw;
    }
}


int main(int argc, char* argv[]) {

    // Select a device and display arrayfire info
    af::setDevice(0);
    af::info();

    fast_PCA();

    return 0;
}
