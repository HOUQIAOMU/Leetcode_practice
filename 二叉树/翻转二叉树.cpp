#include <iostream>
#include <treenode.cpp>
using namespace std;

TreeNode* invertTree(TreeNode* root){
    // 如果空节点，return
    if(root==nullptr) return nullptr;

    // 交换左子树和右子树
    TreeNode* temp = root->right;
    root->right = root->left;
    root->left = temp;

    // 递归交换左子树和右子树
    invertTree(root->left);
    invertTree(root->right);
    return root;
}