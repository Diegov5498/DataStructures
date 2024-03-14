/***************************************************************************************
* Class declaration for Node class
*
*   left and right pointers to be used in Doubly Linked Lists or Binary Tree Structures
*
****************************************************************************************/
class Node {
    public:
    Node(int num) {
        value = num;
        left = nullptr;
        right = nullptr;    
    };
    int value;
    Node* left;
    Node* right;
};