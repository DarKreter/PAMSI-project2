#ifndef ALGORITHMS_PAMSI_PROJECT_DEFINE_H
#define ALGORITHMS_PAMSI_PROJECT_DEFINE_H

#include <string>
#include <tuple>
#include <vector>

namespace pamsi {

/**
 * @brief Partitioning function for quicksort
 *
 * @tparam T type of each element in container
 * @param _vector container
 * @param start start index
 * @param end end index
 * @return size_t start and end position of pivot area
 */
template <typename T>
std::tuple<size_t, size_t> Partition(std::vector<T>& _vector, size_t start,
                                     size_t end);

/**
 * @brief quicksort function. Sorts _vector
 *
 * @tparam T type of each element in container
 * @param _vector container
 * @param start start index
 * @param end end index
 */
template <typename T>
void QuickSort(std::vector<T>& _vector, size_t start, size_t end);

/**
 * @brief Merging function for mergesort
 *
 * @tparam T type of each element in container
 * @param _vector container
 * @param start_1 start index of first block
 * @param end_1 end index of first block
 * @param start_2 start index of second block
 * @param end_2 end index of second block
 */
template <typename T>
void Merge(std::vector<T>& _vector, size_t start_1, size_t end_1,
           size_t start_2, size_t end_2);

/**
 * @brief mergesort function. Sorts _vector
 *
 * @tparam T type of each element
 * @param _vector container
 * @param start start index
 * @param end end index
 */
template <typename T>
void MergeSort(std::vector<T>& _vector, size_t start, size_t end);

/**
 * @brief bucketsort function. Sorts _vector
 *
 * @tparam T type of each element in container
 * @param _vector container
 */
template <typename T>
void BucketSort(std::vector<T>& _vector);

/**
 * @brief Calculate mean value from dataset.
 *
 * @tparam T type of elements in vector
 * @param w vector of T types element
 * @return double mean value
 */
template <typename T>
double CalcMeanValue(const std::vector<T>& w);

/**
 * @brief Calculates middle number for dataset.
 * Treats T objects as number
 * (converstion operator from T to number-like type is mandatory to use this
 * function)
 *
 * @tparam T type of elements in container
 * @param w vector of T types elements
 * @return double middle number
 */
template <typename T>
double CalcMiddleNumber(const std::vector<T>& w);

/**
 * @brief Splitting one string into vector of strings by delimiter
 * (converstion operator from T to number-like type is mandatory to use this
 * function)
 *
 * @param s string to split
 * @param delimiter delimiter string
 * @return std::vector<std::string> vector of splitted elements
 */
std::vector<std::string> SplitCSV(std::string s, std::string delimiter = ",");

} // namespace pamsi

#include "ALGORITHMS.tpp"
#endif // ALGORITHMS_PAMSI_PROJECT_DEFINE_H