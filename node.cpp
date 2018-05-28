#include <cstddef>
#include <iostream>
#include "node.hpp"



Node::Node(int val) : value(val) {
       right = nullptr;
       left = nullptr;
       size = 1;
}

void Node::setChildren(Node* l, Node* r) {
    // all trees must be balanced
    if (l->size != r->size) { throw "Unbalanced tree"; }

    left = l;
    right = r;
    size = l->size + r->size + 1;

}

int Node::getElem(int n) {

   if (n == 0) { return value; } // return root

   // if n is less than half the size, if must be in the left tree
   if (n <= (size - 1)/2) {
       return left->getElem(n-1);
   } else { // otherwise, it must be in the right tree
       return right->getElem( n-((size-1)/2)-1);
   }
}


bool Node::hasChildren() {
    return (left != nullptr) && (right != nullptr);
}
