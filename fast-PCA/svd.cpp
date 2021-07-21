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

using namespace af;

void fast_PCA()
{
    try {
        float h_buffer[] = {1, 4, 2, 5, 3, 6};  // host array
        array in(2, 3, h_buffer);               // copy host data to device

        array u;
        array s_vec;
        array vt;
        svd(u, s_vec, vt, in);

        array s_mat    = diag(s_vec, 0, false);
        array in_recon = matmul(u, s_mat, vt(seq(2), span));

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
