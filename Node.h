#include <string>

class Node
{
private:
    int value;
    int count;
    Node *left;
    Node *right;

public:
    Node();
    Node(int count);
    Node(int count, int value);
    Node(int count, int value, Node *left, Node *right);
    ~Node();

    // std::string to_string();
    int get_value();
    int get_count();
    Node *get_left();
    Node *get_right();
    void set_right(Node *node);
    void set_left(Node *node);
    void set_value(int count);
    void set_count(int value);
};