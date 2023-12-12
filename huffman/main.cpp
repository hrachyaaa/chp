#include <iostream>
#include <string>
#include "huffmanTree.hpp"

int main() {
    HuffmanTree myTree;
    std::string text{"This is my fisrt code!"};
    myTree.buildTree(text);
    myTree.printTree();

    return 0; // Indicates successful completion
}
