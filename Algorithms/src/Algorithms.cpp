#include "Algorithms.hpp"

namespace pamsi {

std::vector<std::string> SplitCSV(std::string s, std::string delimiter)
{
    size_t position = 0;
    std::vector<std::string> wektor;
    // Find first appearance of delimiter and save its position. If there is no
    // delimiter stop loop.
    while((position = s.find(delimiter)) != std::string::npos) {
        // If rigth after delimiter is quotation mark we treat this cell
        // different, because commas inside quotation marks, are not delimiters.
        // So we need go through to next quotation mark
        if(s.at(0) == '"') {

            // Quotation mark inside quotation mark is represented by two
            // quotation mark placed one behind the other
            while(true) {
                // Find next quotation mark
                position = s.substr(1).find("\"");
                // If next one is quotation mark skip this fragment
                if(s.at(position + 2) == '"') {
                    s = s.substr(position + 3);
                    continue;
                }
                // If its single quotation mark, its whole cell
                else
                    break;
            }

            wektor.push_back(s.substr(1, position));
            // Cut element (position + substr + quotation mark + delimiter)
            s = s.substr(position + 3);
        }

        else {
            // Add element to vector from 0 to delimiter
            wektor.push_back(s.substr(0, position));
            // Cut first element with delimiter
            s = s.substr(position + 1);
        }
    }
    // Add whats left
    wektor.push_back(s);

    return wektor;
}

} // namespace pamsi