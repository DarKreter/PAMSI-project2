#include "Movie.hpp"
#include "Algorithms.hpp"
#include <exception>
#include <vector>

namespace pamsi {

Movie_t::Movie_t(std::string s)
{
    // Split string into vector
    auto w = SplitCSV(s);

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
