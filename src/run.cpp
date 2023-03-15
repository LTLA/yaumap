#include "Rcpp.h"
#include "umappp/Umap.hpp"
#include "Status.h"

#ifdef _OPENMP
#include <omp.h>
#endif

template<class S>
Rcpp::List run_iterations(S& sptr, int ndim, int nthreads, int tick) {
    int epoch_limit = 0;
    if (tick) {
        epoch_limit = sptr->status.epoch() + tick;
    }

#ifdef _OPENMP
    omp_set_num_threads(nthreads);
#endif

    sptr->status.run(ndim, sptr->embedding.data(), epoch_limit);

    return Rcpp::List::create(
        Rcpp::NumericVector(sptr->embedding.begin(), sptr->embedding.end()), 
        sptr->status.epoch() == sptr->status.num_epochs()
    );
}

//[[Rcpp::export(rng=false)]]
Rcpp::List run(SEXP status, int ndim, bool force_dynamic, int nthreads, int tick) {
    if (ndim == 2 && !force_dynamic) {
        Rcpp::XPtr<Status2> sptr(status);
        return run_iterations(sptr, ndim, nthreads, tick);
    } else {
        Rcpp::XPtr<Status> sptr(status);
        return run_iterations(sptr, ndim, nthreads, tick);
    }
}
