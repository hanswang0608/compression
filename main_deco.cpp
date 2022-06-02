#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <bits/stdc++.h>
#include <bitset> // library to display bits

#include "Node.h"
#include "Tree.h"

int main(int argc, char **argv);

void decompress_data_to_file(std::unordered_map<char, std::string> codes_table, char file_in_name[]);

void freq_table_storing(char file_in_name[]);

int main(int argc, char **argv)
{
    // credit to the code below goes to https://people.sc.fsu.edu/~jburkardt/cpp_src/hexdump/hexdump.html
    char file_in_name[80];
    int i;

    // If the input file was not specified, get it now.
    if (argc <= 1)
    {
        std::cout << "Please enter the name of a file to be decompressed.\n";

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
    std::cout << "Storing Frequencies in Hashtable for " << file_in_name << std::endl;
    // Hashtable that stores the frequency of each character read from the input
    std::unordered_map<char, int> freq_table;
    // Hashtable that stores the variable length huffman codes for each character
    std::unordered_map<char, std::string> *codes_table;

    // Input file stream
    std::ifstream file_in(file_in_name, std::ios::binary);

    if (!file_in.is_open())
    {
        std::cout << "\n";
        std::cout << "HANDLE - Fatal error!\n";
        std::cout << "  Cannot open \"" << file_in_name << "\"\n";
        return;
    }

    file_in.seekg(0, std::ios::end);

    int file_size = file_in.tellg();

    uint8_t message_length = 0;

    file_in.seekg(file_size-8);

    for (int i = 0; i < 8; i++){

        char c = file_in.get();
        message_length = message_length << 8;
        message_length = c;

    }

    file_in.seekg(file_size-9);
    int message_trail_length = (int)file_in.get();

    file_in.seekg(file_size-10);
    int table_trail_length = (int)file_in.get();
    
    std::cout<<"Message Length is"<<" "<< (int)message_length<<" "<<"bytes"<<std::endl;
    
    std::cout<<"Trail length for message is"<<" "<< message_trail_length<<" "<<"bits"<<std::endl;
    
    std::cout<<"Trail length for table is"<<" "<< table_trail_length<<" "<<"bits"<<std::endl;

    return;
}

// void decompress_data_to_file(){
    
// }

// g++ main.cpp Tree.cpp Node.cpp Huffman.cpp -o compression -lstdc++
// make && ./compression
// valgrind -o --leak-check=yes ./compression

//! Things to Improve
// not opening the input file a second time.
// not writing the output file right away