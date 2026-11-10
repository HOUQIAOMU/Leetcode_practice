#include <iostream>
#include <treenode.cpp>
#include <vector>
using namespace std;

void inorder(TreeNode*root, vector<int>& ans){
    // 递归思想->遍历型递归
    if(root==nullptr) return;
    // 1.遍历左子树
    inorder(root->left, ans);
    // 递归找到其左子树不存在的时候了
    ans.push_back(root->val);
    // 再遍历右树
    inorder(root->right,ans);
}

vector<int> inorderTraversal(TreeNode* root){
    vector<int> ans;
    inorder(root,ans);
    return ans;
}