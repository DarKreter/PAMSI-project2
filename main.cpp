#include "CallArgsParser.hpp"
#include "Movie.hpp"
#include <fstream>
#include <iostream>
#include <vector>

#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char* argv[])
{
    // Get size, algorithm and file name
    auto [fileName, size, algorithmType] = ParseCallArgs(argc, argv);

    ifstream file(fileName);
    string line;
    vector<Movie_t> movies;

    // Open file and read X elements
    // Parse each line and put into Movie class
    getline(file, line);
    while(getline(file, line))
        movies.push_back(Movie_t(line));

    std::copy(std::begin(movies), std::end(movies),
              ostream_iterator<Movie_t>(cout, "\n"));

    // Sort with specified algorithm
    // Also measure time of sorting

    // Calculate mean and middle number

    return 0;
}
