#include "Node.hpp"

int Node::get_value(){
    return this->value;
}

Node* Node::get_left(){
    return this->left;
}

Node* Node::get_right(){
    return this->right;
}