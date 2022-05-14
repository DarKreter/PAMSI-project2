#include "Algorithms.hpp"
#include "Movie.hpp"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Line_t : public string {
};

istream& operator>>(istream& stream, Line_t& line)
{
    getline(stream, line);
    return stream;
}

int main(int argc, [[maybe_unused]] char* argv[])
{
    if(argc != 2)
        throw std::runtime_error("Incorrect call paramters!");

    string iFileName = argv[1];
    string oFileName = iFileName.substr(0, iFileName.rfind('.')) + "_mod" +
                       iFileName.substr(iFileName.rfind('.'));
    ifstream iFile(iFileName);
    ofstream oFile(oFileName);

    auto condition = [](Line_t line) -> bool {
        auto splitted = pamsi::SplitCSV(line);
        if(splitted.at(2) == "")
            return false;
        return true;
    };
    auto start = chrono::steady_clock::now();

    std::copy_if(istream_iterator<Line_t>(iFile), istream_iterator<Line_t>(),
                 ostream_iterator<Line_t>(oFile, "\n"), condition);

    auto end = chrono::steady_clock::now();
    cout << "Elapsed time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;

    iFile.close();
    oFile.close();

    return 0;
}
