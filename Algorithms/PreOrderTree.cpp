#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

Node* buildTree(vector<int>& preOrder);

int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preOrder);

    return 0;
}

static int idx = -1; //Since we're going to build tree using preOrder, so we need to keep track of each index while traversing it.

Node* buildTree(vector<int>& preOrder) {
    idx++; //As we're moving to the next index, idx gets incremented.

    if(preOrder[idx] == -1) return NULL; //If we encounter -1 then there is no node to be created at this point, hence return NULL.

    Node* root = new Node(preOrder[idx]); //Otherwise, we create a new node, store its value, and make it root of the current subtree.

    root->left = buildTree(preOrder); //Now we recursively call the same function to build the left subtree of this node.
    root->right = buildTree(preOrder); //Once left subtree is completed, we move to the right subtree and build it as well.

    return root; //After both left and right subtree have been constructed, return the root of the current subtree.
}
