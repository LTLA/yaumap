#' UMAP from an input matrix
#'
#' Compute UMAP coordinates from an input matrix of observation-level data.
#' This involves a round of nearest neighbor detection before the UMAP iterations themselves.
#'
#' @param indices Integer matrix containing neighbor indices for each observation (rows).
#' @param distances Numeric matrix of distances to neighbors for each observation (rows).
#' @inheritParams umap_from_matrix
#' @param tick Integer scalar specifying the epoch interval to return embeddings in progress.
#'
#' @return 
#' If \code{tick=0}, a single matrix containing the embedding.
#' This has \code{ndim} columns and number of rows equal to \code{nrow(y)}.
#'
#' If \code{tick > 0}, a list of such matrices containing the embedding at each tick.
#'
#' @author Aaron Lun
#'
#' @examples
#' y <- as.matrix(iris[,1:4])
#'
#' library(FNN)
#' nn <- get.knn(y, 15)
#' out <- umap_from_neighbors(nn$nn.idx, nn$nn.dist)
#' plot(out[,1], out[,2], col=iris[,5])
#' 
#' @export
umap_from_neighbors <- function(indices, distances, ..., ndim=2, nthreads=1, tick=0) {
    args <- umap_defaults()
    replace <- list(...)
    for (x in names(replace)) {
        args[[x]] <- replace[[x]]
    }
    ptr <- do.call(setup_parameters, args)
    init <- initialize_from_neighbors(ptr, t(indices) - 1L, t(distances), ndim, nthreads)
    .iterate(init, ndim, nthreads, tick)
}
