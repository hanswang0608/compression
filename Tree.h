#ifndef TREE_HEADER
#define TREE_HEADER

#include <string>
#include <iostream>
#include "Node.h"

class Tree{
    private:
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