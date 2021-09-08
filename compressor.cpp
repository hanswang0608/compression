#include <stdio.h>
#include "Tree.h"

int main(int argc, char** argv){
    Tree t = Tree();
    t.insert('a', 1);
    // t.insert('b', 2);
    t.print_tree();
}