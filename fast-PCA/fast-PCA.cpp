#include <arrayfire.h>

af::array fast_PCA()
{
    try {
        af::array x = af::randn(20, 5, f32);

        af::array m = af::mean(x);
        m = af::tile(m, x.dims()[0]);
        af::array b = x - m;

        af::array u;
        af::array s_vec;
        af::array vt;
        af::svd(u, s_vec, vt, b);
        af::array s_mat    = diag(s_vec, 0, false);

        // flip signs
        u = u * (u / sqrt(u*u));
        vt = vt * (vt / sqrt(vt*vt));

        af::array pca = af::matmul(u(af::span, af::seq(5)), s_mat);
        return pca;

    } catch (af::exception& e) {
        fprintf(stderr, "%s\n", e.what());
        throw;
    }
}
