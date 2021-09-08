#include "Node.h"

Node::Node(){}

Node::Node(char value, unsigned int freq){
    this->value = value;
    this->freq = freq;
}
Node::Node(char value, unsigned int freq, Node* left, Node* right){
    this->value = value;
    this->freq = freq;
    this->left = left;
    this->right = right;
}

Node::~Node(){}

std::string Node::to_string(){
    return std::to_string(this->value);
}

// int Node::get_value(){
//     return this->value;
// }

// Node* Node::get_left(){
//     return this->left;
// }

// Node* Node::get_right(){
//     return this->right;
// }

// void Node::set_left(Node* node){
//     this->left = node;
// }
// void Node::set_right(Node* node){
//     this->right = node;
// }
// void Node::set_value(int value){
//     this->value = value;
// }