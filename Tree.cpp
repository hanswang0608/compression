#include <iostream>
#include "Tree.h"

Tree::Tree(){}
Tree::Tree(Node* root){
    this->root = root;
}
void cleanup_helper(Node* node){
    if (node == nullptr){
        return;
    }
    cleanup_helper(node->left);
    cleanup_helper(node->right);
    delete node;
}

Tree::~Tree(){
    cleanup_helper(this->root);
}

Node* Tree::get_root(){
    return this->root;
}

void Tree::set_root(Node* node){
    this->root = node;
}

void print_tree_helper(Node* node){
    if (node == nullptr){
        return;
    }
    std::cout << node->to_string() << std::endl;
    print_tree_helper(node->left);
    print_tree_helper(node->right);
}

void Tree::print_tree(){
    print_tree_helper(this->get_root());
}