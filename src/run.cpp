#include "Rcpp.h"
#include "umappp/Umap.hpp"

// [[Rcpp::export(rng=false)]]
Rcpp::NumericMatrix run(SEXP status, int ndim, Rcpp::NumericMatrix embedding) {
    Rcpp::XPtr<umappp::Umap::Status> p(status);

    umappp::Umap runner;
    Rcpp::NumericMatrix output = Rcpp::clone(embedding);
    runner.run(*p, ndim, (double*)output.begin());

    return output;
}
