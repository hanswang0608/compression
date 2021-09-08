#ifndef MINHEAP_HEADER
#define MINHEAP_HEADER

class MinHeap{
    private:
    struct Node{
        char value;
        unsigned int freq;
    };
    Node heap[];

    public: 
    MinHeap();
    ~MinHeap();

};

#endif