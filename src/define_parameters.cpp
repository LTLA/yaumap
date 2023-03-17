#include "Rcpp.h"
#include "umappp/Umap.hpp"
#include "Status.h"

//[[Rcpp::export(rng=false)]]
Rcpp::List define_defaults() {
    return Rcpp::List::create(
        Rcpp::Named("local_connectivity") = Rcpp::wrap(Umap::Defaults::local_connectivity),
        Rcpp::Named("bandwidth") = Rcpp::wrap(Umap::Defaults::bandwidth),
        Rcpp::Named("mix_ratio") = Rcpp::wrap(Umap::Defaults::mix_ratio),
        Rcpp::Named("spread") = Rcpp::wrap(Umap::Defaults::spread),
        Rcpp::Named("min_dist") = Rcpp::wrap(Umap::Defaults::min_dist),
        Rcpp::Named("a") = Rcpp::wrap(Umap::Defaults::a),
        Rcpp::Named("b") = Rcpp::wrap(Umap::Defaults::b),
        Rcpp::Named("repulsion_strength") = Rcpp::wrap(Umap::Defaults::repulsion_strength),
        Rcpp::Named("num_epochs") = Rcpp::wrap(Umap::Defaults::num_epochs),
        Rcpp::Named("learning_rate") = Rcpp::wrap(Umap::Defaults::learning_rate),
        Rcpp::Named("negative_sample_rate") = Rcpp::wrap(Umap::Defaults::negative_sample_rate),
        Rcpp::Named("num_neighbors") = Rcpp::wrap(Umap::Defaults::num_neighbors),
        Rcpp::Named("seed") = Rcpp::wrap(Umap::Defaults::seed),
        Rcpp::Named("num_threads") = Rcpp::wrap(Umap::Defaults::num_threads)
    );
}

//[[Rcpp::export(rng=false)]]
SEXP setup_parameters(
    double local_connectivity,
    double bandwidth,
    double mix_ratio,
    double spread,
    double min_dist,
    double a,
    double b,
    double repulsion_strength,
    int num_epochs,
    double learning_rate,
    double negative_sample_rate,
    int num_neighbors,
    int seed,
    int num_threads
) {
    auto ptr = new Umap;
    ptr->set_local_connectivity(local_connectivity);
    ptr->set_bandwidth(bandwidth);
    ptr->set_mix_ratio(mix_ratio);

    ptr->set_spread(spread);
    ptr->set_min_dist(min_dist);
    ptr->set_a(a);
    ptr->set_b(b);

    ptr->set_repulsion_strength(repulsion_strength);
    ptr->set_num_epochs(num_epochs);
    ptr->set_learning_rate(learning_rate);
    ptr->set_negative_sample_rate(negative_sample_rate);

    ptr->set_num_neighbors(num_neighbors);
    ptr->set_seed(seed);
    ptr->set_num_threads(num_threads);

    return Rcpp::XPtr<Umap>(ptr, true);
}
