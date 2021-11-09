#include <stdio.h>
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "Tree.h"
#include "Huffman.h"

int main(int argc, char **argv);
void compress(char file_in_name[]);

int main(int argc, char **argv)
{
    std::cout << "Starting" << std::endl;
    std::cout << '\n';

    //credit to the code below goes to https://people.sc.fsu.edu/~jburkardt/cpp_src/hexdump/hexdump.html
    char file_in_name[80];
    int i;

    // If the input file was not specified, get it now.
    if (argc <= 1)
    {
        std::cout << "\n";
        std::cout << "std::hexDUMP:\n";
        std::cout << "  Please enter the name of a file to be analyzed.\n";

        std::cin.getline(file_in_name, sizeof(file_in_name));

        compress(file_in_name);
    }

    // Otherwise, get the file(s) from the argument list.
    else
    {
        for (i = 1; i < argc; ++i)
        {
            // compress each file specified
            compress(argv[i]);
        }
    }

    return 0;
}

void compress(char file_in_name[])
{
    std::cout << "Compressing " << file_in_name << std::endl;
    // Hashtable that stores the frequency of each character read from the input
    std::unordered_map<char, int> freq_table;
    // Hashtable that stores the variable length huffman codes for each character
    std::unordered_map<char, std::string> codes_table;
    // Input file stream
    std::ifstream file_in;

    // Open the file.
    file_in.open(file_in_name);

    if (!file_in)
    {
        std::cout << "\n";
        std::cout << "HANDLE - Fatal error!\n";
        std::cout << "  Cannot open \"" << file_in_name << "\"\n";
        return;
    }

    // Read file char by char to count the frequency of each character
    while (1)
    {
        char c = file_in.get();
        if (file_in.gcount() <= 0) // No more chars to read, break
        {
            break;
        }
        freq_table[c]++;
    }

    // Print out the frequency hashtable
    for (auto i : freq_table)
    {
        std::cout << i.first << ", " << i.second << std::endl;
    }

    // Close the file.
    file_in.close();

    std::cout << '\n';

    return;
}
