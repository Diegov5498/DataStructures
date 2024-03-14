/***************************************************************************************
* Class declaration for BST class
*
* Not self balancing bst.
* O(log n) to search
*
****************************************************************************************/
#include <iostream>
#include "Node.hh"
#include <vector>
#include <string>

class BinarySearchTree {
    public:
    BinarySearchTree();
    BinarySearchTree(const std::vector<int> source);
    BinarySearchTree(int source[]);
    void insert(int value);
    void remove(int value);
    bool search(int value);
    void inOrder();
    void preOrder();
    void postOrder();
    int getSize() {return size;};

    private:
    Node* root;
    int size;
    Node* deleteNode(Node* root, int value);
    std::string inOrderPrint(Node* root);
    std::string preOrderPrint(Node* root);
    std::string postOrderPrint(Node* root);
};

/*CONSTRUCTORS*/

//Default Constructor
BinarySearchTree::BinarySearchTree() {
    size = 0;
    root = nullptr;
}
//Constructor that converts a vector into BST
BinarySearchTree::BinarySearchTree(const std::vector<int> source) {
    size = 0;
    root = nullptr;
    for (auto& value: source) {
        insert(value);
    }
}

/*INSERTION,DELETION,SEARCH FUNCTIONS*/

//Insert value into tree
void BinarySearchTree::insert(int value) {
    //Check if root exists
    if (!root) {
        root = new Node(value);
        size++;
    } else {
        Node* current = root;
        while (current) {
            if (current->value > value) {
                if (current->left) {
                    current = current->left;
                }else {
                    current->left = new Node(value);
                    size++;
                    return;
                }
            } else if (current->value < value) {
                if(current->right) {
                    current = current->right;
                } else {
                    current->right = new Node(value);
                    size++;
                    return;
                }
            } else {
                return;
            }
        }
    }
}
//Delete value from tree
void BinarySearchTree::remove(int value) {
    deleteNode(root, value);
}
//Helper Function to Delete Node recursively
Node* BinarySearchTree::deleteNode(Node* root, int value) {
    //Check if root is Null
    if (!root) {
        return root;
    } else {
        if (value < root->value) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->value) {
            root->right = deleteNode(root->right, value);
        } else {
            //Root has 0 or 1 child 
            if (!root->left) {
                Node* temp = root->right;
                delete(root);
                size--;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete(root);
                size--;
                return temp;
            //Root has 2 children
            } else {
                Node* temp = root->right;
                while (temp->left) {
                    temp = temp->left;
                }
                root->value = temp->value;
                deleteNode(root->right, temp->value);
            }
        }
    }
    return root;
}
//Searches Tree for a value, returns boolean
bool BinarySearchTree::search(int value) {
    //Check if root
    if(!root) {
        return false;
    }
    Node* current = root;
    while(current) {
        if (current->value == value) {
            return true;
        } else if (value < current->value) {
            current = current->left;
        } else {
            current= current->right;
        }
    }
    return false;
}

/*PRINT METHODS*/

//InOrder Traversal 
void BinarySearchTree::inOrder() {
    std::cout << "[ " << inOrderPrint(root) << "]\n";
}
//InOrder Traversal helper to print recursively
std::string BinarySearchTree::inOrderPrint(Node* root) {
    //Check Root 
    if (!root) {
        return "";
    }

    std::string result = "";
    result.append(inOrderPrint(root->left));
    result.append(" "); result.append(std::to_string(root->value)); result.append(",");
    result.append(inOrderPrint(root->right));
    
    return result;
}
//PreOrder Traversal
void BinarySearchTree::preOrder() {
    std::cout << "[ " << preOrderPrint(root) << "]\n";
}
//preOrder Traversal helper to print recursively
std::string BinarySearchTree::preOrderPrint(Node* root) {
    //Check Root 
    if (!root) {
        return "";
    }

    std::string result = "";
    result.append(" "); result.append(std::to_string(root->value)); result.append(",");
    result.append(preOrderPrint(root->left));
    result.append(preOrderPrint(root->right));
    
    return result;
}
//PostOrder Traversal
void BinarySearchTree::postOrder() {
    std::cout << "[ " << postOrderPrint(root) << "]\n";
}
//postOrder Traversal helper to print recursively
std::string BinarySearchTree::postOrderPrint(Node* root) {
    //Check Root 
    if (!root) {
        return "";
    }

    std::string result = "";
    result.append(postOrderPrint(root->left));
    result.append(postOrderPrint(root->right));
    result.append(" "); result.append(std::to_string(root->value)); result.append(",");

    
    return result;
}