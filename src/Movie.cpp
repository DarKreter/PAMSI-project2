#include "Movie.hpp"
#include <exception>
#include <vector>

std::vector<std::string> Split(std::string s, std::string delimiter = ",")
{
    size_t position = 0;
    std::vector<std::string> wektor;

    while((position = s.find(delimiter)) != std::string::npos) {
        wektor.push_back(s.substr(0, position));
        s = s.substr(position + 1);
    }
    wektor.push_back(s);

    return std::move(wektor);
}

Movie_t::Movie_t(std::string s)
{
    auto w = Split(s);

    if(w.size() != 3)
        throw std::runtime_error("Wrong database!");

    name = w.at(1);

    rating = std::stoi(w.at(2));
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
    stream << movie.GetName() << ": " << movie.GetRating();
    return stream;
}
