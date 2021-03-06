#include "skralist.hpp"
#include <cmath>
#include <iostream>

void Skralist::printdb() {
    // print summary of tree for debugging
    for(auto j = trees.begin(); j != trees.end(); j++) {
        if (*j != nullptr) {
            std::cout << (*j)->value << ";\n";
        } else {
            std::cout << "nullptr;\n";
        }
    }
    std::cout << "\n";
}

void Skralist::pushElem(int val) {

    Node* n = new Node(val);
    
    auto itbegin = trees.begin();

    // if the current front-most trees are the same size (n), we combine them
    // into a new tree of size 2n+1, with the current node as the root.
    // This way, a preorder traversal of the tree will maintain the list order.
    if (trees.size() >= 2) {
        Node* left = *itbegin;
        Node* right = *std::next(itbegin, 1);
        if (left->size == right->size) {
            n->setChildren(left, right);
            trees.pop_front();
            trees.pop_front();
            trees.push_front(n);
        } else { // if they are not the same size, then we push another 
                 // 1-tree on the front of the list
            trees.push_front(n);
        }
    } else { // if there are less than two trees in the list, then we push
             // another 1-tree on the front
        trees.push_front(n);

    }
}



int Skralist::head() {
    
    auto fst = trees.begin();
    if (*fst != nullptr) {
         return (*fst)->value; // always return the root of the tree
    }
    throw "The list is empty";    
}


int Skralist::pop() {
    auto fst = trees.begin();
    if (*fst == nullptr) {
        throw "The list is empty";    
    }

    else if (!(*fst)->hasChildren()) {
        int retval = trees.front()->value;
        trees.pop_front();
        return retval;
    }

    else {
        int retval = (*fst)->value;
        Node* l = (*fst)->left;
        Node* r = (*fst)->right;

        *fst = r;
        trees.push_front(l);

        return retval;

    }


return 0;
}


int Skralist::getElem(int n) {

    int numPassed = 0; // the num of elements in previous trees

    // iterate through the list until we get to a tree which 
    // contains the nth element.
    for (auto i = trees.begin(); i != trees.end(); ++i) {
        Node* currTree = *i;
        int treeSize = currTree->size;
        numPassed += treeSize;
        if (n < numPassed) { 
            return currTree->getElem(treeSize-(numPassed-n));
        }
    }
    throw "Index out of bound error";    
}

void Skralist::drop(int n) {
    int fstTreeSize = trees.front()->size;
    if (fstTreeSize <= n) {
        trees.pop_front();
        this->drop(n-fstTreeSize);
    } else {
        if(n >= 1) {
            this->pop();
            this->drop(n-1);
        }
    }
}


Skralist::iterator Skralist::end() {
    return iterator();
}

Skralist::iterator Skralist::begin() {
    return iterator(*this);
}
