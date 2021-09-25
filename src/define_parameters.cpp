#include "Rcpp.h"
#include "umappp/Umap.hpp"

//[[Rcpp::export(rng=false)]]
Rcpp::List define_defaults() {
    return Rcpp::List::create(
        Rcpp::Named("local_connectivity") = Rcpp::wrap(umappp::Umap::Defaults::local_connectivity),
        Rcpp::Named("bandwidth") = Rcpp::wrap(umappp::Umap::Defaults::bandwidth),
        Rcpp::Named("mix_ratio") = Rcpp::wrap(umappp::Umap::Defaults::mix_ratio),
        Rcpp::Named("spread") = Rcpp::wrap(umappp::Umap::Defaults::spread),
        Rcpp::Named("min_dist") = Rcpp::wrap(umappp::Umap::Defaults::min_dist),
        Rcpp::Named("a") = Rcpp::wrap(umappp::Umap::Defaults::a),
        Rcpp::Named("b") = Rcpp::wrap(umappp::Umap::Defaults::b),
        Rcpp::Named("repulsion_strength") = Rcpp::wrap(umappp::Umap::Defaults::repulsion_strength),
        Rcpp::Named("num_epochs") = Rcpp::wrap(umappp::Umap::Defaults::num_epochs),
        Rcpp::Named("learning_rate") = Rcpp::wrap(umappp::Umap::Defaults::learning_rate),
        Rcpp::Named("negative_sample_rate") = Rcpp::wrap(umappp::Umap::Defaults::negative_sample_rate),
        Rcpp::Named("num_neighbors") = Rcpp::wrap(umappp::Umap::Defaults::num_neighbors),
        Rcpp::Named("seed") = Rcpp::wrap(umappp::Umap::Defaults::seed),
        Rcpp::Named("batch") = Rcpp::wrap(umappp::Umap::Defaults::batch)
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
    bool batch
) {
    auto ptr = new umappp::Umap;
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
    ptr->set_batch(batch);

    return Rcpp::XPtr<umappp::Umap>(ptr, true);
}
