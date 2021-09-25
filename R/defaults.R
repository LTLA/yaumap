#' UMAP defaults
#'
#' Default parameters for the UMAP algorithm.
#' Values here are passed to the \pkg{umappp} C++ library.
#'
#' @return Named list of parameters with their defaults.
#'
#' @author Aaron Lun
#'
#' @examples
#' defaults()
#'
#' @export
umap_defaults <- function() {
    define_defaults()
}
