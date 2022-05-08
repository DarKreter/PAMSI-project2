#ifndef ALGORITHM_TYPE_PAMSI_PROJECT_DEFINE_H
#define ALGORITHM_TYPE_PAMSI_PROJECT_DEFINE_H

#include <string>
#include <tuple>

namespace pamsi {

/**
 * @brief enum type to identify which sort argument user wants to use.
 */
enum algorithmType_t
{
    quicksort,
    mergesort,
    bucketsort
};

/**
 * @brief Parsing command line arguments
 *
 * @param argc arguments counter
 * @param argv arguments vector
 * @return std::tuple<std::string, uint32_t, algorithmType_t> fileName, desired
 * size, algorithm type to use when sorting
 */
std::tuple<std::string, uint32_t, algorithmType_t> ParseCallArgs(int argc,
                                                                 char* argv[]);

} // namespace pamsi

#endif // ALGORITHM_TYPE_PAMSI_PROJECT_DEFINE_H