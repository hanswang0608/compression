#include <stdio.h>
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <bits/stdc++.h>
#include <bitset> // library to display bits

#include "Node.h"
#include "Tree.h"

int main(int argc, char **argv);
void freq_table_storing(char file_in_name[]);
void print_freq_table(std::unordered_map<char, int> freq_table);
void print_codes_table(std::unordered_map<char, std::string> codes_table);
Node *huffman_tree_maker(std::unordered_map<char, int> freq_table);
Node *node_comparator(Node *node1, Node *node2);
bool Compare(Node *node1, Node *node2);
std::unordered_map<char, std::string> *generate_codes(Node *root);
void compress_data_to_file(std::unordered_map<char, std::string> codes_table, char file_in_name[], Node *root);
void safe_tree_to_file(Node *root, std::ofstream file_out);
void safe_letter_to_file(Node *root, std::ofstream file_out);

int main(int argc, char **argv){
    // credit to the code below goes to https://people.sc.fsu.edu/~jburkardt/cpp_src/hexdump/hexdump.html
    char file_in_name[80];
    int i;

    // If the input file was not specified, get it now.
    if (argc <= 1)
    {
        std::cout << "Please enter the name of a file to be compressed.\n";

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

void freq_table_storing(char file_in_name[]){
    std::cout << "Storing Frequencies in Hashtable for " << file_in_name << std::endl;
    // Hashtable that stores the frequency of each character read from the input
    std::unordered_map<char, int> freq_table;
    // Hashtable that stores the variable length huffman codes for each character
    std::unordered_map<char, std::string> *codes_table;
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
    std::cout << "-----------------------" << std::endl;

    Node *root = huffman_tree_maker(freq_table);

    codes_table = generate_codes(root);
    std::cout << "-----------------------" << std::endl;
    print_codes_table(*codes_table);

    compress_data_to_file(*codes_table, file_in_name, root);

    // Close the file.
    file_in.close();
    Node::cleanup(root);
    codes_table->clear();
    delete codes_table;

    return;
}

// comparator for the nodes, it returns true if the first one is greater, and false other wise, this allows for it to be sorted from least to greatest
bool Compare(Node *node1, Node *node2){
    if (node1->get_count() >= node2->get_count())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// creates huffman tree
Node *huffman_tree_maker(std::unordered_map<char, int> freq_table){
    // creates a priority_queue to store and sort the whole huffman tree
    std::priority_queue<Node *, std::vector<Node *>, decltype(&Compare)> pq(Compare);

    // go through all the frequency table values and create a node for each, and then store it into the queue
    for (auto i : freq_table)
    {
        Node *current = new Node(i.second, i.first);
        pq.push(current);
    }

    // go through each node, and join all the lowest ones together until there is only 1 left.
    while (pq.size() != 1)
    {

        // get the lowest node
        Node *temp = pq.top();
        // remove the lowest node
        pq.pop();

        // combine the lowest node, with the next lowest node (top)
        Node *combo = new Node(temp->get_count() + pq.top()->get_count(), 9000, temp, pq.top());

        // push the new combined node to the list
        pq.push(combo);
        // pop the next lowest that was used
        pq.pop();
    }

    return pq.top();
}

// Helper function for traversing the huffman tree and generating codes
void generate_codes_helper(std::unordered_map<char, std::string> *map, Node *root, std::string str){
    if (root->get_left() == nullptr && root->get_right() == nullptr)
    {
        map->insert(std::make_pair(root->get_value(), str));
        return;
    }

    generate_codes_helper(map, root->get_left(), str + "0");
    generate_codes_helper(map, root->get_right(), str + "1");
}

// Return a hashtable with characters and their corresponding variable length huffman codes
std::unordered_map<char, std::string> *generate_codes(Node *root){
    std::cout << "Generating variable length codes for all characters" << std::endl;
    std::unordered_map<char, std::string> *temp = new std::unordered_map<char, std::string>();
    generate_codes_helper(temp, root, "");
    return temp;
}

// Prints the frequency table
void print_freq_table(std::unordered_map<char, int> freq_table){
    // Print out the frequency hashtable in hex
    for (auto i : freq_table)
    {
        std::cout << std::fixed << std::setprecision(2) << std::setfill('0');
        std::cout << std::setw(2) << std::hex << (int)(unsigned char)i.first << ", ";
        std::cout << std::dec << i.second << std::endl;
    }
}

// Prints the character codes table
void print_codes_table(std::unordered_map<char, std::string> codes_table){
    // Print out the frequency hashtable in hex
    for (auto i : codes_table)
    {
        std::cout << std::fixed << std::setprecision(2) << std::setfill('0');
        std::cout << std::setw(2) << std::hex << (int)(unsigned char)i.first << ", ";
        std::cout << std::dec << i.second << std::endl;
    }
}

void safe_tree_to_file(Node *root, std::ofstream file_out){

}

void safe_letter_to_file(Node *root, std::ofstream file_out){

}


void compress_data_to_file(std::unordered_map<char, std::string> codes_table, char file_in_name[],Node *root){

    // Create file to write compression into
    std::string file_out_name = "compressed - " + std::string(file_in_name);
    // open the output file
    std::ofstream file_out(file_out_name);

    // open the input file.
    std::ifstream file_in;
    file_in.open(file_in_name);

    // 1 byte, 8 bit buffer
    uint8_t buffer = 0;

    // status of buffer
    int buffer_stat = 0;

    uint64_t byte_counter = 0;

    // loop to write to file and replace the characters
    while (true){
        // get the character from input file
        char c = file_in.get();

        if (file_in.gcount() <= 0) // No more chars to read, break
        {
            // push final byte to be MSB if there are any trailing 0's
            buffer = buffer << 8 - buffer_stat;
            // Byte counter
            byte_counter++;

            // std::cout << "this is written to file: " << std::bitset<8>(buffer) << ", hex value: " << std::hex << (int)buffer << std::endl;

            // write final byte
            file_out << (char)buffer;

            buffer = 0;
            break;
        }

        // get the code for the corresponding characater
        std::string letter_code = codes_table.at(c);

        // std::cout << "char: " << c << std::endl;
        // std::cout << "code: " << letter_code << std::endl;

        // loop through the code and add it to the buffer 1 bit at the time
        for (int i = 0; i < letter_code.length(); i++)
        {
            // once buffer is full
            if (buffer_stat == 8)
            {
                // std::cout << "this is written to file: " << std::bitset<8>(buffer) << ", hex value: " << std::hex << (int)buffer << std::endl;

                // write byte to file
                file_out << (char)buffer;
                buffer = 0;
                buffer_stat = 0;
                byte_counter++;
            }

            // get current bit from the code
            char current_bit = letter_code[i];

            // shift buffer to make room for the new bit
            buffer = buffer << 1;

            // make the bit either 1 or 0
            int bit_set = current_bit - 48;

            // set the bit at the first location
            buffer = buffer | bit_set;

            // increase the buffer status size
            buffer_stat++;
        }
    }

    uint8_t buffer_stat_copy = buffer_stat;

    

    file_out << buffer_stat_copy;

    // std::cout << "this is written to file: " << std::bitset<64>(byte_counter) << ", hex value: " << std::hex << (int)byte_counter << std::endl;

    uint8_t temp_byte = 0;

    for (int i = 7; i >= 0; i--)
    {
        temp_byte = byte_counter >> 8 * i;

        // std::cout << "this is written to file: " << std::bitset<8>(temp_byte) << ", hex value: " << std::hex << (int)temp_byte << std::endl;
        file_out << temp_byte;
    }

    // close
    file_in.close();
    file_out.close();
}

// g++ main.cpp Tree.cpp Node.cpp Huffman.cpp -o compression -lstdc++
// cd OneDrive/Desktop/Projects/compression/
// make && ./compression
// valgrind -o --leak-check=yes ./compression

//! Things to Improve
// not opening the input file a second time.
// not writing the output file right away