#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <stdint.h>
#include <string>

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

#endif // MOVIE_H