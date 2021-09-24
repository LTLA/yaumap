#include "Rcpp.h"
#include "umappp/Umap.hpp"
#include "knncolle/knncolle.hpp"

//[[Rcpp::export(rng=false)]]
Rcpp::List initialize_from_matrix(Rcpp::NumericMatrix data, int n_neighbors, std::string nn_method, int ndim) {
    const double* y = static_cast<const double*>(data.begin());
    int nd = data.nrow();
    int nobs = data.ncol();

    std::unique_ptr<knncolle::Base<> > ptr;
    if (nn_method == "Annoy") {
        ptr.reset(new knncolle::AnnoyEuclidean<>(nd, nobs, y));
    } else {
        ptr.reset(new knncolle::KmknnEuclidean<>(nd, nobs, y));
    }

    Rcpp::NumericMatrix output(ndim, nobs);
    umappp::Umap runner;
    auto status = runner.initialize(ptr.get(), ndim, (double*)output.begin());

    typedef decltype(status) Status;
    auto sptr = new Status(std::move(status));
    return Rcpp::List::create(Rcpp::XPtr<Status>(sptr, true), output);
}
