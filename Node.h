#include <string>

class Node{
    private:

    public:
    Node();
    Node(char value, unsigned int freq);
    Node(char value, unsigned int freq, Node* left, Node* right);
    ~Node();
    char value;
    unsigned int freq;
    Node* left;
    Node* right;
    
    std::string to_string();
    // int get_value();
    // Node* get_left();
    // Node* get_right();
    // void set_right(Node* node);
    // void set_left(Node* node);
    // void set_value(int value);
};