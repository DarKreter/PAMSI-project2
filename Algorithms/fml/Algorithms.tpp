#include "Algorithms.hpp"
#include <numeric>

#include <iostream>

namespace pamsi {

template <typename T>
size_t Partition(std::vector<T>& _vector, size_t start, size_t end)
{
    size_t p = end;
    size_t new_p = start;
    for(size_t i = start; i < end; i++) {
        if(_vector.at(i) < _vector.at(p)) {
            std::swap(_vector.at(i), _vector.at(new_p));
            new_p++;
        }
    }
    std::swap(_vector[new_p], _vector[p]);
    return new_p;
}

template <typename T>
void QuickSort(std::vector<T>& _vector, size_t start, size_t end)
{
    if(start >= end)
        return;

    size_t new_p = Partition(_vector, start, end);
    QuickSort(_vector, start, new_p - 1);
    QuickSort(_vector, new_p + 1, end);
}

template <typename T>
double CalcMeanValue(const std::vector<T>& w)
{
    double sum = std::accumulate(std::begin(w), std::end(w), 0);

    return sum / w.size();
}

template <typename T>
double CalcMiddleNumber(const std::vector<T>& wektor)
{
    if(wektor.size() % 2)
        return wektor.at(wektor.size() / 2);
    else
        return (wektor.at(wektor.size() / 2 - 1) +
                wektor.at(wektor.size() / 2)) /
               2.;
}

} // namespace pamsi