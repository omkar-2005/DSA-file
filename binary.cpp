#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
};

class BST {
public:
    TreeNode *root;

    BST() {
        root = nullptr;
    }

    void insert(int);
    void deleteNode(int);
    void inorderTraversal(TreeNode *);
    void preorderTraversal(TreeNode *);
    void postorderTraversal(TreeNode *);
    void displayTree();
private:
    TreeNode* findMin(TreeNode *);
    TreeNode* deleteNodeHelper(TreeNode *, int);
};

// Function to insert a node in BST
void BST::insert(int data) {
    TreeNode *newNode = new TreeNode{data, nullptr, nullptr};
    if (!root) {
        root = newNode;
        return;
    }
    TreeNode *current = root, *parent = nullptr;

    while (current) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

// Helper function to find the minimum value node
TreeNode* BST::findMin(TreeNode *node) {
    while (node->left)
        node = node->left;
    return node;
}

// Helper function to delete a node
TreeNode* BST::deleteNodeHelper(TreeNode *node, int data) {
    if (!node)
        return nullptr;

    if (data < node->data)
        node->left = deleteNodeHelper(node->left, data);
    else if (data > node->data)
        node->right = deleteNodeHelper(node->right, data);
    else {
        // Node with one child or no child
        if (!node->left) {
            TreeNode *temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            TreeNode *temp = node->left;
            delete node;
            return temp;
        }

        // Node with two children
        TreeNode *temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNodeHelper(node->right, temp->data);
    }
    return node;
}

// Function to delete a node from the BST
void BST::deleteNode(int data) {
    root = deleteNodeHelper(root, data);
}

// Function for inorder traversal
void BST::inorderTraversal(TreeNode *node) {
    if (node) {
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
}

// Function for preorder traversal
void BST::preorderTraversal(TreeNode *node) {
    if (node) {
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

// Function for postorder traversal
void BST::postorderTraversal(TreeNode *node) {
    if (node) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }
}

// Function to display the tree
void BST::displayTree() {
    cout << "\nInorder Traversal: ";
    inorderTraversal(root);
    cout << "\nPreorder Traversal: ";
    preorderTraversal(root);
    cout << "\nPostorder Traversal: ";
    postorderTraversal(root);
    cout << endl;
}

// Main function
int main() {
    BST tree;
    int choice, value;

    do {
        cout << "\n--- Binary Search Tree Operations ---";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display Tree";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            tree.deleteNode(value);
            break;
        case 3:
            tree.displayTree();
            break;
        case 4:
            cout << "Exiting program.";
            break;
        default:
            cout << "Invalid choice! Please try again.";
        }
    } while (choice != 4);

    return 0;
}
