#ifndef MOVIE_PAMSI_PROJECT_DEFINE_H
#define MOVIE_PAMSI_PROJECT_DEFINE_H

#include <iostream>
#include <stdint.h>
#include <string>

namespace pamsi {

/**
 * @brief Class which can store single movie object. It has movie name and
 * rating. It can be constructed from single line from proper csv file.
 *
 */
class Movie_t {
    std::string _title;
    short _rating;

public:
    /**
     * @brief Construct a new Movie_t object from string
     *
     * @param s string should be in format "{no},{title},{rating}"
     * It will parse title to _title and rating into _rating
     */
    Movie_t(std::string s);
    /**
     * @brief Construct a new Movie_t object from title and rating
     *
     * @param n title of the movie
     * @param rat rating of the movie
     */
    Movie_t(std::string n, short rat) : _title{n}, _rating{rat} {}

    /**
     * @brief Get the object title
     *
     * @return std::string title
     */
    std::string GetTitle() const { return _title; }
    /**
     * @brief Get the Rating object
     *
     * @return short rating
     */
    short GetRating() const { return _rating; }

    /**
     * @brief Comparison operators based on rating values
     */
    bool operator<(const Movie_t& second);
    bool operator>(const Movie_t& second);
    bool operator<=(const Movie_t& second);
    bool operator>=(const Movie_t& second);
    bool operator==(const Movie_t& second);
    bool operator!=(const Movie_t& second);

    /**
     * @brief conversion operator to double
     *
     * @return double it's just rating value.
     */
    operator double() const { return _rating; }
};

/**
 * @brief overloaded stream operator for debug purpose
 */
std::ostream& operator<<(std::ostream&, const Movie_t&);

} // namespace pamsi

#endif // MOVIE_PAMSI_PROJECT_DEFINE_H