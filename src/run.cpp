#include "Rcpp.h"
#include "umappp/Umap.hpp"

//[[Rcpp::export(rng=false)]]
Rcpp::NumericMatrix run(SEXP params, SEXP status, int ndim, Rcpp::NumericMatrix embedding, int tick = 0) {
    Rcpp::XPtr<umappp::Umap> pptr(params);
    Rcpp::XPtr<umappp::Umap::Status> sptr(status);

    int epoch_limit = 0;
    if (tick) {
        epoch_limit = sptr->epoch() + tick;
    }

    Rcpp::NumericMatrix output = Rcpp::clone(embedding);
    pptr->run(*sptr, ndim, (double*)output.begin(), epoch_limit);
    return output;
}
