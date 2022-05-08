#ifndef SORT_PAMSI_PROJECT_DEFINE_H
#define SORT_PAMSI_PROJECT_DEFINE_H

#include "Movie.hpp"
#include <vector>

namespace pamsi {

double CalcMeanValue(const std::vector<Movie_t>&);
} // namespace pamsi

#include "Sort.tpp"
#endif // SORT_PAMSI_PROJECT_DEFINE_H