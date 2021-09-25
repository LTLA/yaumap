#include "Rcpp.h"
#include "umappp/Umap.hpp"
#include "knncolle/knncolle.hpp"

//[[Rcpp::export(rng=false)]]
Rcpp::List initialize_from_matrix(SEXP params, Rcpp::NumericMatrix data, std::string nn_method, int ndim) {
    const double* y = static_cast<const double*>(data.begin());
    int nd = data.nrow();
    int nobs = data.ncol();

    std::unique_ptr<knncolle::Base<> > ptr;
    if (nn_method == "Annoy") {
        ptr.reset(new knncolle::AnnoyEuclidean<>(nd, nobs, y));
    } else {
        ptr.reset(new knncolle::KmknnEuclidean<>(nd, nobs, y));
    }

    Rcpp::XPtr<umappp::Umap> uptr(params);
    Rcpp::NumericMatrix output(ndim, nobs);
    auto status = uptr->initialize(ptr.get(), ndim, (double*)output.begin());

    typedef decltype(status) Status;
    auto sptr = new Status(std::move(status));
    return Rcpp::List::create(Rcpp::XPtr<Status>(sptr, true), output);
}
