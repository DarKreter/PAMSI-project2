#include "Algorithms.hpp"
#include <numeric>

#include <iostream>

namespace pamsi {

template <typename T>
size_t Partition(std::vector<T>& _vector, size_t start, size_t end)
{
    // Set pivot at the end
    size_t p = end;
    size_t new_p = start;
    // Get through all elements and change positions if they are smaller than
    // pivot
    for(size_t i = start; i < end; i++) {
        if(_vector[i] < _vector[p]) {
            // Swap them
            std::swap(_vector[i], _vector[new_p]);
            new_p++;
        }
    }
    //
    std::swap(_vector[new_p], _vector[p]);
    return new_p;
}

template <typename T>
void QuickSort(std::vector<T>& _vector, size_t start, size_t end)
{
    // If start is greater or equal end
    if(start >= end)
        return; // That means we reach base condition of recursion

    // Divide container into two smaller
    size_t new_p = Partition(_vector, start, end);

    // Sort them
    QuickSort(_vector, start, (new_p == 0 ? 0 : new_p - 1));
    QuickSort(_vector, new_p + 1, end);
}

template <typename T>
void Merge(std::vector<T>& _vector, size_t start_1, size_t end_1,
           size_t start_2, size_t end_2)
{
    std::vector<T> temp;
    // Go through elements in first and second block
    for(size_t i = start_1, j = start_2; i <= end_1 || j <= end_2;) {
        if(i > end_1)                     // If first one is empty
            temp.push_back(_vector[j++]); // Add second
        else if(j > end_2)                // If second is empty
            temp.push_back(_vector[i++]); // Add first

        // If both not empty add smaller
        else if(_vector.at(i) < _vector[j])
            temp.push_back(_vector[i++]);
        else
            temp.push_back(_vector[j++]);
    }
    for(size_t i = start_1, j = 0; i <= end_2; i++, j++)
        _vector[i] = temp[j];
}

template <typename T>
void MergeSort(std::vector<T>& _vector, size_t start, size_t end)
{
    // base condition
    if(start >= end)
        return;

    // Calculate middle
    size_t help = (end - start) / 2 + start;
    // Sort divided subvectors
    MergeSort(_vector, start, help);
    MergeSort(_vector, help + 1, end);
    // Merge two sorted blocks
    Merge(_vector, start, help, help + 1, end);
}

template <typename T>
double CalcMeanValue(const std::vector<T>& w)
{
    double sum = std::accumulate(std::begin(w), std::end(w), 0);
    //, [](int a, T b) {return a + b.GetRating();});

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