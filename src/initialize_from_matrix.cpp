#include "Rcpp.h"
#include "umappp/Umap.hpp"
#include "knncolle/knncolle.hpp"
#include "Status.h"

//[[Rcpp::export(rng=false)]]
SEXP initialize_from_matrix(SEXP params, Rcpp::NumericMatrix data, std::string nn_method, int ndim) {
    const double* y = static_cast<const double*>(data.begin());
    int nd = data.nrow();
    int nobs = data.ncol();

    std::unique_ptr<knncolle::Base<int, Float> > ptr;
    if (nn_method == "Annoy") {
        ptr.reset(new knncolle::AnnoyEuclidean<int, Float>(nd, nobs, y));
    } else {
        ptr.reset(new knncolle::KmknnEuclidean<int, Float>(nd, nobs, y));
    }

    Rcpp::XPtr<Umap> uptr(params);
    std::vector<Float> embedding(ndim * nobs);
    auto status = uptr->initialize(ptr.get(), ndim, embedding.data());

    return Rcpp::XPtr<Status>(new Status(std::move(status), std::move(embedding)));
}
