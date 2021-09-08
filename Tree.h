#ifndef TREE_HEADER
#define TREE_HEADER

#include <string>
#include <iostream>

class Tree{
    private:

    struct Node{
        int value;
        Node* left;
        Node* right;

        Node();
        Node(int value);
        Node(int value, Node* left, Node* right);
        ~Node();
    };

    Node* root;

    public:
    Tree();
    Tree(Node* root);
    ~Tree();
    
    void print_tree();
    Node* get_root();
    void set_root(Node* node);
    
};
#endif