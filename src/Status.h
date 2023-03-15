#ifndef YAUMAP_STATUS_H
#define YAUMAP_STATUS_H

#include <vector>

typedef float Float;

typedef typename umappp::Umap<Float> Umap;

typedef typename umappp::Umap<Float, 2> Umap2;

struct Status {
    Status(Umap::Status s, std::vector<Float> e) : status(std::move(s)), embedding(std::move(e)) {}
    Umap::Status status;
    std::vector<Float> embedding;
};

struct Status2 {
    Status2(Umap2::Status s, std::vector<Float> e) : status(std::move(s)), embedding(std::move(e)) {}
    Umap2::Status status;
    std::vector<Float> embedding;
};


#endif
