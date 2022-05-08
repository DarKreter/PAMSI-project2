#include "Movie.hpp"
#include <exception>
#include <vector>

namespace pamsi {

/**
 * @brief Splitting one string into vector of strings by delimiter
 *
 * @param s string to split
 * @param delimiter delimiter string
 * @return std::vector<std::string> vector of splitted elements
 */
std::vector<std::string> Split(std::string s, std::string delimiter = ",")
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

    return std::move(wektor);
}

Movie_t::Movie_t(std::string s)
{
    // Split string into vector
    auto w = Split(s);

    // parsing format should have 3 positions in csv
    if(w.size() != 3)
        throw std::runtime_error("Wrong database!");

    _title = w.at(1);
    _rating = std::stoi(w.at(2));
}

bool Movie_t::operator<(const Movie_t& second)
{
    return _rating < second._rating;
}
bool Movie_t::operator>(const Movie_t& second)
{
    return _rating > second._rating;
}
bool Movie_t::operator<=(const Movie_t& second)
{
    return _rating <= second._rating;
}
bool Movie_t::operator>=(const Movie_t& second)
{
    return _rating >= second._rating;
}
bool Movie_t::operator==(const Movie_t& second)
{
    return _rating == second._rating;
}
bool Movie_t::operator!=(const Movie_t& second)
{
    return _rating != second._rating;
}

uint32_t operator+(uint32_t first, Movie_t movie)
{
    return first + movie.GetRating();
}

std::ostream& operator<<(std::ostream& stream, const Movie_t& movie)
{
    stream << movie.GetTitle() << ": " << movie.GetRating();
    return stream;
}

} // namespace pamsi
