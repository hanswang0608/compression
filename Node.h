#include <string>

class Node{
    private:
    int value;
    Node* left;
    Node* right;

    public:
    Node();
    Node(int value);
    Node(int value, Node* left, Node* right);
    ~Node();
    
    std::string to_string();
    int get_value();
    Node* get_left();
    Node* get_right();
    void set_right(Node* node);
    void set_left(Node* node);
    void set_value(int value);
};