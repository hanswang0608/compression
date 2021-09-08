#include <iostream>
#include "Tree.h"


Tree::Node::Node(){}

Tree::Node::Node(char value){
    this->value = value;
}
Tree::Node::Node(Node* left, Node* right){
    this->left = left;
    this->right = right;
}

Tree::Node::~Node(){}

Tree::Tree(){
    this->root = nullptr;
    freq = 0;
}

Tree::Tree(Node* root){
    this->root = root;
    freq = 0;
}

void Tree::cleanup_helper(Node* node){
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


void Tree::set_root(Node* node){
    this->root = node;
}

void Tree::print_tree_helper(Node* node){
    if (node == nullptr){
        return;
    }
    std::cout << node->value << std::endl;
    print_tree_helper(node->left);
    print_tree_helper(node->right);
}

void Tree::print_tree(){
    print_tree_helper(this->root);
}

void Tree::insert(char a, unsigned int freq){
    this->root = new Node(this->root, new Node(a));
    this->freq += freq;
}

void Tree::insert(Tree t){}