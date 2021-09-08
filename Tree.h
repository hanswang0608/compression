#ifndef TREE_HEADER
#define TREE_HEADER

#include <string>
#include <iostream>

class Tree{
    private:

    struct Node{
        char value;
        Node* left;
        Node* right;

        Node();
        Node(char value);
        Node(Node* left, Node* right);
        ~Node();
    };

    Node* root;
    unsigned int freq;

    public:
    Tree();
    Tree(Node* root);
    ~Tree();
    
    void print_tree();
    void set_root(Node* node);
    void cleanup_helper(Node* node);
    void print_tree_helper(Node* node);
    void insert(char a, unsigned int freq);
    void insert(Tree t);
    
};
#endif