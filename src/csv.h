#include <cstring>
#include <string>
#include <iostream>
#include <fstream>

namespace csv
{
    int parseRow(std::string, char *, char *[], int &);
    int parseFileRows(std::ifstream *, std::string[], int &);
    int parseFileRows(std::ifstream *, std::string[], std::string *, int &);
} // namespace csv
