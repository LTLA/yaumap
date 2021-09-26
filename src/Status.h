#ifndef YAUMAP_STATUS_H
#define YAUMAP_STATUS_H

#include <vector>

typedef float Float;

typedef typename umappp::Umap<Float> Umap;

struct Status {
    Status(Umap::Status s, std::vector<Float> e) : status(std::move(s)), embedding(std::move(e)) {}
    Umap::Status status;
    std::vector<Float> embedding;
};

#endif
