


class Node
{

public:
    int value;
    Node* right;
    Node* left;

    // Constructors
    
    // construct a node with a value pointing to nothing
    Node(int val) : value(val) {
       // pointers default to Null
       right = NULL;
       left = NULL;
    }

private:
    // nothing, for now


};
