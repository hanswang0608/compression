#include <stdio.h>
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <bits/stdc++.h>

#include "Node.h"

int main(int argc, char **argv);
void freq_table_storing(char file_in_name[]);
void print_freq_table(std::unordered_map<char, int> freq_table);
void huffman_tree_maker(std::unordered_map<char, int> freq_table);
Node *node_comparator(Node *node1, Node *node2);

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
    std::cout << "-----------------------" << std::endl;
    huffman_tree_maker(freq_table);

    // Close the file.
    file_in.close();

    return;
}

// comparator for the nodes, it returns true if the first one is greater, and false other wise, this allows for it to be sorted from least to greatest
bool Compare(Node *node1, Node *node2)
{
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
void huffman_tree_maker(std::unordered_map<char, int> freq_table)
{
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

    // print out the top of the tree (the node starts with pq.top so if wanted in a node variable, assign to to one)
    std::cout << std::endl
              << pq.top()->get_count() << std::endl;
}

// Prints the frequency table
void print_freq_table(std::unordered_map<char, int> freq_table)
{
    // Print out the frequency hashtable in hex
    for (auto i : freq_table)
    {
        std::cout << std::fixed << std::setprecision(2) << std::setfill('0');
        std::cout << std::setw(2) << std::hex << (int)(unsigned char)i.first << ", ";
        std::cout << std::dec << i.second << std::endl;
    }
}

// g++ main.cpp Tree.cpp Node.cpp Huffman.cpp -o compression -lstdc++
// cd OneDrive/Desktop/Projects/compression/
// make && ./compression
// valgrind -o --leak-check=yes ./compression
