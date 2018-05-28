


class Node
{

public:
    int value;
    Node* right;
    Node* left;
    int size;

    
    /*
     * construct a node with a given value and no children
     */
    Node(int val);

    /* get the value stored in the nth node,
     * using a preorder traversal.
     * This only works on balanced trees.
     * O(log(n))
     */
    int getElem(int n);

    /*
     * sets the left and right children of a node
     * the children must be the same size--all trees must be balanced
     * O(1)
     */
    void setChildren(Node* l, Node* r);

    /*
     * Returns true if the Node has children, and false otherwise
     */
    bool hasChildren();


private:
    // nothing, for now


};
