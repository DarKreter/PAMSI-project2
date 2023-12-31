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

std::ostream& operator<<(std::ostream& stream, const Movie_t& movie)
{
    stream << movie.GetTitle() << ": " << movie.GetRating();
    return stream;
}

} // namespace pamsi
