#include "Rcpp.h"
#include "umappp/Umap.hpp"

//[[Rcpp::export(rng=false)]]
Rcpp::List initialize_from_neighbors(SEXP params, Rcpp::IntegerMatrix indices, Rcpp::NumericMatrix distances, int ndim) {
    int nr = indices.nrow(), nc = indices.ncol();
    umappp::NeighborList x(nc);
    for (int i = 0; i < nc; ++i) {
        auto curi = indices.column(i);
        auto curd = distances.column(i);
        for (int j = 0; j < nr; ++j) { 
            x[i].emplace_back(curi[j], curd[j]);
        }
    }

    Rcpp::XPtr<umappp::Umap> uptr(params);
    Rcpp::NumericMatrix output(ndim, nc);
    auto status = uptr->initialize(std::move(x), ndim, (double*)output.begin());

    typedef decltype(status) Status;
    auto sptr = new Status(std::move(status));
    return Rcpp::List::create(Rcpp::XPtr<Status>(sptr, true), output);
}
