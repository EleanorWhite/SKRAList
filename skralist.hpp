#include "node.hpp"
#include <list>

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
     */
    int head();


    // debugging function
    // prints the root value in each element of the list
    void printdb();
private:

    // DATA MEMBERS

    // the list of trees
    std::list<Node*> trees;



};
