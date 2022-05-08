#include "Sort.hpp"
#include <numeric>

namespace pamsi {

double CalcMeanValue(const std::vector<Movie_t>& wektor)
{
    double sum = std::accumulate(std::begin(wektor), std::end(wektor), 0);

    return sum / wektor.size();
}
} // namespace pamsi