#' UMAP from an input matrix
#'
#' Compute UMAP coordinates from an input matrix of observation-level data.
#' This involves a round of nearest neighbor detection before the UMAP iterations themselves.
#'
#' @param y Numeric matrix of observations (rows) and variables (columns).
#' @param ... Further arguments to change the defaults, see \code{\link{umap_defaults}}.
#' @param method String specifying the neighbor detection algorithm to use.
#' @param ndim Integer scalar specifying the number of embedding dimensions to return.
#' @param nthreads Integer scalar specifying the number of threads to use.
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
#' out <- umap_from_matrix(y)
#' plot(out[,1], out[,2], col=iris[,5])
#' 
#' @export
umap_from_matrix <- function(y, ..., method=c("Annoy", "VPTree"), ndim=2, nthreads=1, tick=0) {
    args <- umap_defaults()
    replace <- list(...)
    for (x in names(replace)) {
        args[[x]] <- replace[[x]]
    }
    ptr <- do.call(setup_parameters, args)
    init <- initialize_from_matrix(ptr, t(y), match.arg(method), ndim, nthreads)
    .iterate(init, ndim, nthreads, tick)
}

.iterate <- function(init, ndim, nthreads, tick) {
    if (tick == 0) {
        X <- run(init, nthreads, 0)
        matrix(X[[1]], ncol=ndim, byrow=TRUE)
    } else {
        collected <- list()
        bail <- FALSE 

        while (!bail) {
            out <- run(init, nthreads, tick)
            collected <- c(collected, list(matrix(out[[1]], ncol=ndim, byrow=TRUE)))
            bail <- out[[2]]
        }
        collected
    }
}
