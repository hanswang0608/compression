#ifndef MINHEAP_HEADER
#define MINHEAP_HEADER

class MinHeap{
    private:
struct Node{
        char value;
        Node* left;
        Node* right;

        Node();
        Node(char value);
        Node(Node* left, Node* right);
        ~Node();
    };
    public: 
    MinHeap();
    ~MinHeap();

};

#endif