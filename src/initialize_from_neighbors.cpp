#include "Rcpp.h"
#include "umappp/Umap.hpp"
#include "Status.h"

#ifdef _OPENMP
#include <omp.h>
#endif

//[[Rcpp::export(rng=false)]]
SEXP initialize_from_neighbors(SEXP params, Rcpp::IntegerMatrix indices, Rcpp::NumericMatrix distances, int ndim, bool force_dynamic, int nthreads) {
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

    std::vector<Float> embedding(ndim * nc);

    if (ndim == 2 && !force_dynamic) {
        Rcpp::XPtr<Umap2> uptr(params);
        auto status2 = uptr->initialize(std::move(x), ndim, embedding.data());
        return Rcpp::XPtr<Status2>(new Status2(std::move(status2), std::move(embedding)));
    } else {
        Rcpp::XPtr<Umap> uptr(params);
        auto status = uptr->initialize(std::move(x), ndim, embedding.data());
        return Rcpp::XPtr<Status>(new Status(std::move(status), std::move(embedding)));
    }
}
