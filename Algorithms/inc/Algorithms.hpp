#ifndef ALGORITHMS_PAMSI_PROJECT_DEFINE_H
#define ALGORITHMS_PAMSI_PROJECT_DEFINE_H

#include <string>
#include <vector>


namespace pamsi {

/**
 * @brief Calculate mean value from dataset.
 *  Use operator+(int, T).
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
 *
 * @param s string to split
 * @param delimiter delimiter string
 * @return std::vector<std::string> vector of splitted elements
 */
std::vector<std::string> Split(std::string s, std::string delimiter = ",");

} // namespace pamsi

#include "ALGORITHMS.tpp"
#endif // ALGORITHMS_PAMSI_PROJECT_DEFINE_H