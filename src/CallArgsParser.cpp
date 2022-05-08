#include "CallArgsParser.hpp"
#include <cstring>
#include <stdexcept>

namespace pamsi {

std::tuple<std::string, uint32_t, algorithmType_t> ParseCallArgs(int argc,
                                                                 char* argv[])
{
    // Check quantity of args
    if(argc != 4)
        throw std::runtime_error("Incorrect call paramters!");

    // Try to match algorithm type
    algorithmType_t algorithmType;
    if(!strcmp(argv[3], "quicksort"))
        algorithmType = quicksort;
    else if(!strcmp(argv[3], "mergesort"))
        algorithmType = mergesort;
    else if(!strcmp(argv[3], "bucketsort"))
        algorithmType = bucketsort;
    else
        throw std::runtime_error("Incorrect call paramters!");

    // Return tuple
    return {argv[1], std::stoi(std::string(argv[2])), algorithmType};
}

} // namespace pamsi
