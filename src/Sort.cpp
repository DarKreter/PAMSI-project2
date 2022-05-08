#include "Sort.hpp"
#include <numeric>

namespace pamsi {

double CalcMeanValue(const std::vector<Movie_t>& wektor)
{
    double sum = std::accumulate(std::begin(wektor), std::end(wektor), 0);

    return sum / wektor.size();
}

double CalcMiddleNumber(const std::vector<Movie_t>& wektor)
{
    if(wektor.size() % 2)
        return wektor.at(wektor.size() / 2).GetRating();
    else
        return (wektor.at(wektor.size() / 2 - 1).GetRating() +
                wektor.at(wektor.size() / 2).GetRating()) /
               2.;
}

} // namespace pamsi