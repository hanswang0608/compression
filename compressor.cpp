#include <stdio.h>
#include "Tree.h"

int main(int argc, char** argv){
    Tree t = Tree(new Node(5, new Node(3), new Node(4)));
    t.print_tree();
}