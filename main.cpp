#include <stdio.h>
#include "Tree.h"
#include "Huffman.h"
#include <map>
#include <unordered_map>

int main(int argc, char** argv){
    // Hashtable that stores the frequency of each character read from the input
    std::unordered_map<char, int> freq_table;

    // Hashtable that stores the variable length huffman codes for each character
    std::unordered_map<char, std::string> codes_table;
}