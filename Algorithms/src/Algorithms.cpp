#include "Algorithms.hpp"

namespace pamsi {

std::vector<std::string> Split(std::string s, std::string delimiter)
{
    size_t position = 0;
    std::vector<std::string> wektor;
    // Find first appearance of delimiter and save its position. If there is no
    // delimiter stop loop.
    while((position = s.find(delimiter)) != std::string::npos) {
        // Add element to vector from 0 to delimiter
        wektor.push_back(s.substr(0, position));
        // Cut first element with delimiter
        s = s.substr(position + 1);
    }
    // Add whats left
    wektor.push_back(s);

    return wektor;
}

} // namespace pamsi