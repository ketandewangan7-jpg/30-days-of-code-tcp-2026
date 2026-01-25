#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void inorder(TreeNode* root, vector<int>& in) {
    if (root == NULL) return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

void preorder(TreeNode* root, vector<int>& pre) {
    if (root == NULL) return;
    pre.push_back(root->data);
    preorder(root->left, pre);
    preorder(root->right, pre);
}

void postorder(TreeNode* root, vector<int>& post) {
    if (root == NULL) return;
    postorder(root->left, post);
    postorder(root->right, post);
    post.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root) {
    vector<int> in, pre, post;
    inorder(root, in);
    preorder(root, pre);
    postorder(root, post);
    return {in, pre, post};
}
