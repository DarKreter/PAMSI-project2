#ifndef ALGORITHMTYPE_H
#define ALGORITHMTYPE_H

#include <string>
#include <tuple>


enum algorithmType_t
{
    quicksort,
    mergesort,
    bucketsort
};

std::tuple<std::string, uint32_t, algorithmType_t> ParseCallArgs(int argc,
                                                                 char* argv[]);

#endif // ALGORITHMTYPE_H