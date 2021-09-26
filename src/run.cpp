#include "Rcpp.h"
#include "umappp/Umap.hpp"
#include "Status.h"

#ifdef _OPENMP
#include <omp.h>
#endif

//[[Rcpp::export(rng=false)]]
Rcpp::List run(SEXP params, SEXP status, int ndim, int nthreads, int tick = 0) {
    Rcpp::XPtr<Umap> pptr(params);
    Rcpp::XPtr<Status> sptr(status);

    int epoch_limit = 0;
    if (tick) {
        epoch_limit = sptr->status.epoch() + tick;
    }

#ifdef _OPENMP
    omp_set_num_threads(nthreads);
#endif

    pptr->run(sptr->status, ndim, sptr->embedding.data(), epoch_limit);

    return Rcpp::List::create(
        Rcpp::NumericVector(sptr->embedding.begin(), sptr->embedding.end()), 
        sptr->status.epoch() == sptr->status.num_epochs()
    );
}
