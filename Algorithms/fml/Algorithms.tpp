#include "Algorithms.hpp"
#include <map>
#include <numeric>


namespace pamsi {

template <typename T>
std::tuple<size_t, size_t> Partition(std::vector<T>& _vector, size_t start,
                                     size_t end)
{
    // Set pivot at the end
    T p = _vector[end];
    size_t new_p_start = start;
    size_t new_p_end = end;

    // Get through all elements
    for(size_t i = start; i <= new_p_end; i++) {
        if(_vector[i] < p) {
            if(i != new_p_start)
                std::swap(_vector[i], _vector[new_p_start]);
            new_p_start++;
        }
        else if(_vector[i] > p && i != new_p_end) {
            std::swap(_vector[i], _vector[new_p_end]);
            new_p_end--;
            i--;
        }
    }

    return {new_p_start, new_p_end};
}

template <typename T>
void QuickSort(std::vector<T>& _vector, size_t start, size_t end)
{
    // If start is greater or equal end
    if(start >= end)
        return; // That means we reach base condition of recursion

    // Divide container into two smaller
    auto [p_start, p_end] = Partition(_vector, start, end);

    // Sort them
    QuickSort(_vector, start, (p_start == 0 ? 0 : p_start - 1));
    QuickSort(_vector, p_end, end);
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
void BucketSort(std::vector<T>& _vector)
{
    std::map<size_t, std::vector<T>> pom;

    for(const auto& elem : _vector)
        pom[elem - 1].push_back(elem);

    size_t i = 0;
    for(auto v : pom)
        for(auto elem : v.second)
            _vector[i++] = elem;
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