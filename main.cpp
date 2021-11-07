#include <stdio.h>
#include "Tree.h"
#include "Simple.h"

void func(){
    Tree * t2 = new Tree(new Node(5));
}

int main(int argc, char** argv){
    Tree t = Tree(new Node(5, new Node(3), new Node(4)));
    t.print_tree();
    func();
    Simple::compress("testing new2");
}