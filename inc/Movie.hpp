#ifndef MOVIE_PAMSI_PROJECT_DEFINE_H
#define MOVIE_PAMSI_PROJECT_DEFINE_H

#include <iostream>
#include <stdint.h>
#include <string>

namespace pamsi {

class Movie_t {
    short rating;
    std::string name;

public:
    Movie_t(std::string);

    std::string GetName() const { return name; }
    short GetRating() const { return rating; }

    bool operator<(const Movie_t& second);
    bool operator>(const Movie_t& second);
    bool operator<=(const Movie_t& second);
    bool operator>=(const Movie_t& second);
    bool operator==(const Movie_t& second);
    bool operator!=(const Movie_t& second);
};

std::ostream& operator<<(std::ostream&, const Movie_t&);

} // namespace pamsi

#endif // MOVIE_PAMSI_PROJECT_DEFINE_H