// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// define_defaults
Rcpp::List define_defaults();
RcppExport SEXP _yaumap_define_defaults() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    rcpp_result_gen = Rcpp::wrap(define_defaults());
    return rcpp_result_gen;
END_RCPP
}
// setup_parameters
SEXP setup_parameters(double local_connectivity, double bandwidth, double mix_ratio, double spread, double min_dist, double a, double b, double repulsion_strength, int num_epochs, double learning_rate, double negative_sample_rate, int num_neighbors, int seed, int num_threads);
RcppExport SEXP _yaumap_setup_parameters(SEXP local_connectivitySEXP, SEXP bandwidthSEXP, SEXP mix_ratioSEXP, SEXP spreadSEXP, SEXP min_distSEXP, SEXP aSEXP, SEXP bSEXP, SEXP repulsion_strengthSEXP, SEXP num_epochsSEXP, SEXP learning_rateSEXP, SEXP negative_sample_rateSEXP, SEXP num_neighborsSEXP, SEXP seedSEXP, SEXP num_threadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< double >::type local_connectivity(local_connectivitySEXP);
    Rcpp::traits::input_parameter< double >::type bandwidth(bandwidthSEXP);
    Rcpp::traits::input_parameter< double >::type mix_ratio(mix_ratioSEXP);
    Rcpp::traits::input_parameter< double >::type spread(spreadSEXP);
    Rcpp::traits::input_parameter< double >::type min_dist(min_distSEXP);
    Rcpp::traits::input_parameter< double >::type a(aSEXP);
    Rcpp::traits::input_parameter< double >::type b(bSEXP);
    Rcpp::traits::input_parameter< double >::type repulsion_strength(repulsion_strengthSEXP);
    Rcpp::traits::input_parameter< int >::type num_epochs(num_epochsSEXP);
    Rcpp::traits::input_parameter< double >::type learning_rate(learning_rateSEXP);
    Rcpp::traits::input_parameter< double >::type negative_sample_rate(negative_sample_rateSEXP);
    Rcpp::traits::input_parameter< int >::type num_neighbors(num_neighborsSEXP);
    Rcpp::traits::input_parameter< int >::type seed(seedSEXP);
    Rcpp::traits::input_parameter< int >::type num_threads(num_threadsSEXP);
    rcpp_result_gen = Rcpp::wrap(setup_parameters(local_connectivity, bandwidth, mix_ratio, spread, min_dist, a, b, repulsion_strength, num_epochs, learning_rate, negative_sample_rate, num_neighbors, seed, num_threads));
    return rcpp_result_gen;
END_RCPP
}
// initialize_from_matrix
SEXP initialize_from_matrix(SEXP params, Rcpp::NumericMatrix data, std::string nn_method, int ndim);
RcppExport SEXP _yaumap_initialize_from_matrix(SEXP paramsSEXP, SEXP dataSEXP, SEXP nn_methodSEXP, SEXP ndimSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< SEXP >::type params(paramsSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type data(dataSEXP);
    Rcpp::traits::input_parameter< std::string >::type nn_method(nn_methodSEXP);
    Rcpp::traits::input_parameter< int >::type ndim(ndimSEXP);
    rcpp_result_gen = Rcpp::wrap(initialize_from_matrix(params, data, nn_method, ndim));
    return rcpp_result_gen;
END_RCPP
}
// initialize_from_neighbors
SEXP initialize_from_neighbors(SEXP params, Rcpp::IntegerMatrix indices, Rcpp::NumericMatrix distances, int ndim);
RcppExport SEXP _yaumap_initialize_from_neighbors(SEXP paramsSEXP, SEXP indicesSEXP, SEXP distancesSEXP, SEXP ndimSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< SEXP >::type params(paramsSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerMatrix >::type indices(indicesSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type distances(distancesSEXP);
    Rcpp::traits::input_parameter< int >::type ndim(ndimSEXP);
    rcpp_result_gen = Rcpp::wrap(initialize_from_neighbors(params, indices, distances, ndim));
    return rcpp_result_gen;
END_RCPP
}
// run
Rcpp::List run(SEXP status, int nthreads, int tick);
RcppExport SEXP _yaumap_run(SEXP statusSEXP, SEXP nthreadsSEXP, SEXP tickSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< SEXP >::type status(statusSEXP);
    Rcpp::traits::input_parameter< int >::type nthreads(nthreadsSEXP);
    Rcpp::traits::input_parameter< int >::type tick(tickSEXP);
    rcpp_result_gen = Rcpp::wrap(run(status, nthreads, tick));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_yaumap_define_defaults", (DL_FUNC) &_yaumap_define_defaults, 0},
    {"_yaumap_setup_parameters", (DL_FUNC) &_yaumap_setup_parameters, 14},
    {"_yaumap_initialize_from_matrix", (DL_FUNC) &_yaumap_initialize_from_matrix, 4},
    {"_yaumap_initialize_from_neighbors", (DL_FUNC) &_yaumap_initialize_from_neighbors, 4},
    {"_yaumap_run", (DL_FUNC) &_yaumap_run, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_yaumap(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
