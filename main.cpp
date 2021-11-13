#include <stdio.h>
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "Tree.h"
#include "Huffman.h"

int main(int argc, char **argv);
void freq_table_storing(char file_in_name[]);
void print_freq_table(std::unordered_map<char, int> freq_table);

int main(int argc, char **argv)
{
    //credit to the code below goes to https://people.sc.fsu.edu/~jburkardt/cpp_src/hexdump/hexdump.html
    char file_in_name[80];
    int i;

    // If the input file was not specified, get it now.
    if (argc <= 1)
    {
        std::cout << "Please enter the name of a file to be analyzed.\n";

        std::cin.getline(file_in_name, sizeof(file_in_name));

        freq_table_storing(file_in_name);
    }

    // Otherwise, get the file(s) from the argument list.
    else
    {
        for (i = 1; i < argc; ++i)
        {
            // compress each file specified
            freq_table_storing(argv[i]);
        }
    }

    return 0;
}

void freq_table_storing(char file_in_name[])
{
    std::cout << "Storing Frequencies in Hashtable " << file_in_name << std::endl;
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

    // Read file 1 char at a time to count the frequency of each character
    // Since a character is actually 1 byte, it counts the frequency of unique bytes
    while (true)
    {
        char c = file_in.get();
        if (file_in.gcount() <= 0) // No more chars to read, break
        {
            break;
        }
        freq_table[c]++;
    }

    print_freq_table(freq_table);

    // Close the file.
    file_in.close();

    return;
}

void print_freq_table(std::unordered_map<char, int> freq_table)
{
    // Print out the frequency hashtable in hex
    for (auto i : freq_table)
    {
        std::cout << std::hex << (int)(unsigned char)i.first << ", " << i.second << std::endl;
    }
}

// g++ main.cpp Tree.cpp Node.cpp Huffman.cpp -o compression -lstdc++
// cd OneDrive/Desktop/Projects/compression/