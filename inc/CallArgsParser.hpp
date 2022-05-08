#ifndef ALGORITHM_TYPE_PAMSI_PROJECT_DEFINE_H
#define ALGORITHM_TYPE_PAMSI_PROJECT_DEFINE_H

#include <string>
#include <tuple>

namespace pamsi {

enum algorithmType_t
{
    quicksort,
    mergesort,
    bucketsort
};

std::tuple<std::string, uint32_t, algorithmType_t> ParseCallArgs(int argc,
                                                                 char* argv[]);

} // namespace pamsi

#endif // ALGORITHM_TYPE_PAMSI_PROJECT_DEFINE_H