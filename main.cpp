#include <stdio.h>
#include "Tree.h"
#include "Simple.h"

int main(int argc, char** argv){
    Tree t = Tree(new Node(5, new Node(3), new Node(4)));
    t.print_tree();
    Simple::compress("testing new");
}