#include "Algorithms.hpp"
#include "Movie.hpp"
#include <fstream>
#include <iostream>
#include <vector>

#include <algorithm>
#include <iterator>

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

    std::copy_if(istream_iterator<Line_t>(iFile), istream_iterator<Line_t>(),
                 ostream_iterator<Line_t>(oFile, "\n"), condition);

    iFile.close();
    oFile.close();

    return 0;
}
