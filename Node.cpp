#include "Node.h"

void Node::cleanup(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    cleanup(node->get_left());
    cleanup(node->get_right());
    delete node;
}

Node::Node()
{
    this->count = 0;
    this->value = 0;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(int count)
{
    this->count = count;
    this->left = nullptr;
    this->right = nullptr;
}
Node::Node(int count, int value)
{
    this->count = count;
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}
Node::Node(int count, int value, Node *left, Node *right)
{
    this->value = value;
    this->count = count;
    this->left = left;
    this->right = right;
}

Node::~Node() {}

std::string Node::to_string()
{
    return std::to_string(this->value);
}

int Node::get_value()
{
    return this->value;
}

int Node::get_count()
{
    return this->count;
}

Node *Node::get_left()
{
    return this->left;
}

Node *Node::get_right()
{
    return this->right;
}

void Node::set_left(Node *node)
{
    this->left = node;
}
void Node::set_right(Node *node)
{
    this->right = node;
}
void Node::set_value(int value)
{
    this->value = value;
}
void Node::set_count(int count)
{
    this->count = count;
}
