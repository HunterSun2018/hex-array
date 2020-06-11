#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <iterator>
#include <algorithm>
#include <iomanip>

using namespace std;

void print_hex(string_view file_name);

int main(int argc, const char *argv[])
{
    try
    {
        if (argc < 2)
        {
            cout << "usage : hex file" << endl;
            return 0;
        }

        print_hex(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

void print_hex(string_view file_name)
{
    ifstream ifs(file_name.data());
    istreambuf_iterator<char> beg(ifs), eos;

    for_each(beg, eos, [](char c) {
        //cout << "0x" << std::setfill('0') << std::setw(2) << std::hex << (int)(uint8_t)c << ", ";
        cout << (int)(uint8_t)c << ", ";
    });

    cout << endl;
}