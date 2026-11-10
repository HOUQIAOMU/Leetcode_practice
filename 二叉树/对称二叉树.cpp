#include <iostream>
#include <treenode.cpp>
#include <vector>
using namespace std;

bool check(TreeNode* left, TreeNode* right){
    if(left == nullptr && right == nullptr){
        return true;
    }
    if(left == nullptr || right == nullptr){
        return false;
    }

    if(left->val != right->val){
        return false;
    }

    bool outside = check(left->left, right->right);
    bool inside = check(left->right, right->left);
    return outside && inside;

}

bool isSemmetric(TreeNode* root){
    if(root == nullptr){
        return true;
    }
    return check(root->left, root->right);

}