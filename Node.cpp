#include "Node.h"

Node::Node(){
    this->value = 0;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(int value){
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}
Node::Node(int value, Node* left, Node* right){
    this->value = value;
    this->left = left;
    this->right = right;
}

Node::~Node(){}

std::string Node::to_string(){
    return std::to_string(this->value);
}

int Node::get_value(){
    return this->value;
}

Node* Node::get_left(){
    return this->left;
}

Node* Node::get_right(){
    return this->right;
}

void Node::set_left(Node* node){
    this->left = node;
}
void Node::set_right(Node* node){
    this->right = node;
}
void Node::set_value(int value){
    this->value = value;
}