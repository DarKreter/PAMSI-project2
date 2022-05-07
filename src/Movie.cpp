#include "Movie.hpp"

Movie_t::Movie_t(std::string)
{
    name = "lol";
    rating = 10;
}

bool Movie_t::operator<(const Movie_t& second)
{
    return rating < second.rating;
}
bool Movie_t::operator>(const Movie_t& second)
{
    return rating > second.rating;
}
bool Movie_t::operator<=(const Movie_t& second)
{
    return rating <= second.rating;
}
bool Movie_t::operator>=(const Movie_t& second)
{
    return rating >= second.rating;
}
bool Movie_t::operator==(const Movie_t& second)
{
    return rating == second.rating;
}
bool Movie_t::operator!=(const Movie_t& second)
{
    return rating != second.rating;
}

std::ostream& operator<<(std::ostream& stream, const Movie_t& movie)
{
    stream << movie.GetName() << ": " << movie.GetRating() << std::endl;
    return stream;
}