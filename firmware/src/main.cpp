#include "Algorithms.hpp"
#include "CallArgsParser.hpp"
#include "Movie.hpp"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

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

    // Sort with specified algorithm
    // Also measure time of sorting
    auto start = chrono::steady_clock::now();

    switch(algorithmType) {
    case pamsi::algorithmType_t::quicksort:
        pamsi::QuickSort(movies, 0, movies.size() - 1);
        break;
    case pamsi::algorithmType_t::bucketsort:
        // bucketsort
        break;
    case pamsi::algorithmType_t::mergesort:
        pamsi::MergeSort(movies, 0, movies.size() - 1);
        break;
    }

    auto end = chrono::steady_clock::now();

    // ofstream oFile("test.csv");
    // std::copy(std::begin(movies), std::end(movies),
    //           ostream_iterator<pamsi::Movie_t>(oFile, "\n"));

    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << ",";

    // Calculate mean and middle number
    cout << pamsi::CalcMeanValue(movies) << ",";
    cout << pamsi::CalcMiddleNumber(movies) << endl;

    return 0;
}
