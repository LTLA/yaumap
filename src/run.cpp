#include "Rcpp.h"
#include "umappp/Umap.hpp"
#include "Status.h"

#ifdef _OPENMP
#include <omp.h>
#endif

//[[Rcpp::export(rng=false)]]
Rcpp::List run(SEXP status, int nthreads, int tick = 0) {
    Rcpp::XPtr<Status> sptr(status);

    int epoch_limit = 0;
    if (tick) {
        epoch_limit = sptr->status.epoch() + tick;
    }

    sptr->status.run(epoch_limit);

    return Rcpp::List::create(
        Rcpp::NumericVector(sptr->embedding.begin(), sptr->embedding.end()), 
        sptr->status.epoch() == sptr->status.num_epochs()
    );
}
