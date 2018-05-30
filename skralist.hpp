#include "node.hpp"
#include <list>
#include <iostream>

class Skralist 
{
public:
    
    /*
     * Pushes an element on to the front of the list
     * O(1)
     */
    void pushElem(int val);
   
    /*
     * Returns the value at index i
     * O(i)
     */
    int getElem(int i);

    /*
     * Returns the value at the front of the list
     * O(1)
     */
    int head();

    /*
     * Returns and deletes the value at the front of the list
     * O(1)
     */
    int pop();

    /*
     * Drops the first n elements from the list.
     */
    void drop(int n);

    class iterator
    {
        public:
            
            // Creates an iterator for the beginning of the skralist
            iterator(Skralist s) {
                 // start out by adding the root of each tree to the list
                 for(auto tree = s.trees.begin(); tree != s.trees.end(); ++tree) {
                    nodes.push_back(*tree);
                 }
            }

            // An iterator to the end is just one where nodes is an empty list
            iterator() {
                // nothing to do here
            }

            iterator operator++() {
                Node* currNode = nodes.front();
                // pop the last element, and push it's direct children
                // this gets you a preorder traversal of each tree
                nodes.pop_front();
                if (currNode->hasChildren()) {
                    nodes.push_front(currNode->right);
                    nodes.push_front(currNode->left);
                }
                return *this;
            }
            
            // The first node in nodes is the element the iterator is pointing to
            int operator*() { return (nodes.front())->value; }
            
            
            bool operator==(const iterator& rhs) const { 
                // all iterators to the end of a list should be equal
                if(rhs.nodes.empty() && nodes.empty()) {
                    return true;
                }
                return nodes == rhs.nodes;
            }
            bool operator!=(const iterator& rhs) const { return !(*this == rhs); }
        private:
            // the standard list for preorder traversals
            std::list<Node*> nodes;
    };

    iterator begin();

    iterator end();


    // debugging function
    // prints the root value in each element of the list
    void printdb();
private:

    // DATA MEMBERS

    // the list of trees
    std::list<Node*> trees;



};
