#include <iostream>
#include <fstream>

struct TreeNode {
    int value;
    TreeNode* leftChild;
    TreeNode* rightChild;

    // Constructor for convenience
    TreeNode(int val) : value(val), leftChild(nullptr), rightChild(nullptr) {}
};

// Insetr new element in tree
TreeNode* insert(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    if (val < root->value) {
        root->leftChild = insert(root->leftChild, val);
    } else if (val > root->value) {
        root->rightChild = insert(root->rightChild, val);
    }
    return root;
}

// Find maximum value in tree
int findMax(TreeNode* root) {
    while (root->rightChild) {
        root = root->rightChild;
    }
    return root->value;
}

// Find minimum value in tree
int findMin(TreeNode* root) {
    while (root->leftChild) {
        root = root->leftChild;
    }
    return root->value;
}

// Number of elements in tree
int countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
    return 1 + countNodes(root->leftChild) + countNodes(root->rightChild);
}

// Print binary tree as a sotred array
void printAsSorted(TreeNode* root, std::ofstream & output) {
    if (root) {
        printAsSorted(root->leftChild, output);
        output << root->value << std::endl;
        printAsSorted(root->rightChild, output);
    }
}

int main() {
    std::ifstream input("INPUT.txt");
    std::ofstream output("OUTPUT.txt");
    
    TreeNode* root = nullptr;

    int element;
    input >> element;

    while (element != 0) {
        root = insert(root, element);
        input >> element;
    }

    // Print number of nodes
    int nodeCount = countNodes(root);
    output << nodeCount << std::endl;
    
    // Print maximum value
    int maxVal = findMax(root);
    output << maxVal << std::endl;

    // Pirnt minimum value
    int minValue = findMin(root);
    output << minValue << std::endl;    

    // Print tree
    printAsSorted(root, output);

    input.close();
    output.close();

    return 0;
}