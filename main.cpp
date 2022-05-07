#include "CallArgsParser.hpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    auto [fileName, size, algorithmType] = ParseCallArgs(argc, argv);

    cout << fileName << " " << size << " " << int(algorithmType);
    // Get size, algorithm and file name

    // Open file and read X elements
    // Parse each line and put into Movie struct

    // Sort with specified algorithm
    // Also measure time of sorting

    // Calculate mean and middle number

    return 0;
}
