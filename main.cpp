#include "CallArgsParser.hpp"
#include "Movie.hpp"
#include "Sort.hpp"
#include <fstream>
#include <iostream>
#include <vector>

#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char* argv[])
{
    // Get size, algorithm and file _title
    auto [fileName, size, algorithmType] = pamsi::ParseCallArgs(argc, argv);

    vector<pamsi::Movie_t> movies;

    // Open file and read X elements
    // Parse each line and put into Movie class
    ifstream file(fileName);
    string line;
    uint32_t currentSize = 0;

    // Get csv header
    getline(file, line);
    // Read line by line until end of file or reaching desired size
    while(getline(file, line) && currentSize++ != size)
        movies.push_back(
            pamsi::Movie_t(line)); // Movie_t has parsing constructor

    std::copy(std::begin(movies), std::end(movies),
              ostream_iterator<pamsi::Movie_t>(cout, "\n"));

    // Sort with specified algorithm
    // Also measure time of sorting

    // Calculate mean and middle number
    cout << pamsi::CalcMeanValue(movies) << endl;
    cout << pamsi::CalcMiddleNumber(movies) << endl;

    return 0;
}
