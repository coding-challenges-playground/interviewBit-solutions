#include <iostream>
using namespace std;

// class for tree node
class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left=NULL;
        right = NULL;
    }
};

bool isTreesIdentical(Node* root1, Node* root2) {
    // base case
    // this means that the trees do not have the same height, hence not identical at all
    if ((root1 == NULL && root2) || (root2 == NULL && root1)) {
        return false;
    }

    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    // rec case
    bool isLeftIdentical = isTreesIdentical(root1->left, root2->left);
    bool isRightIdentical = isTreesIdentical(root1->right, root2->right);

    if (isLeftIdentical and isRightIdentical) {
        return true;
    }
    return false;
}

int main() {
    Node* root1 = NULL;
    root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    Node* root2 = NULL;
    root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    // function call to check if the two trees are identical
    bool isIdentical = isTreesIdentical(root1, root2);
    if (isIdentical) {
        cout<<"identical"<<endl;
    }
    else {
        cout<<"Not identical"<<endl;
    }
    return 0;
}
