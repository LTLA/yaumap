#include "Rcpp.h"
#include "umappp/Umap.hpp"
#include "Status.h"

#ifdef _OPENMP
#include <omp.h>
#endif

//[[Rcpp::export(rng=false)]]
SEXP initialize_from_neighbors(SEXP params, Rcpp::IntegerMatrix indices, Rcpp::NumericMatrix distances, int ndim, int nthreads) {
    int nr = indices.nrow(), nc = indices.ncol();
    umappp::NeighborList<Float> x(nc);
    for (int i = 0; i < nc; ++i) {
        auto curi = indices.column(i);
        auto curd = distances.column(i);
        for (int j = 0; j < nr; ++j) { 
            x[i].emplace_back(curi[j], curd[j]);
        }
    }

#ifdef _OPENMP
    omp_set_num_threads(nthreads);
#endif

    Rcpp::XPtr<Umap> uptr(params);
    std::vector<Float> embedding(ndim * nc);
    auto status = uptr->initialize(std::move(x), ndim, embedding.data());

    return Rcpp::XPtr<Status>(new Status(std::move(status), std::move(embedding)));
}
