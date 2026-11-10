#include <iostream>
#include <treenode.cpp>
#include <climits>
using namespace std;

bool check(TreeNode* root, long long lower, long long upper){
    // 先确认停止边界
    if(root==nullptr) return true;
    // 检查当前节点的val是否满足要求
    if(root->val <= lower || root->val >= upper){
        return false;
    }
    // 递归检查左节点和右节点
    // 在递归过程中，lower和upper动态变化了
    bool check_left = check(root->left, lower, root->val);
    bool check_right = check(root->right, root->val, upper);
    return check_left&&check_right;
}

bool isValidBST(TreeNode* root){
    return check(root,LLONG_MIN,LLONG_MAX);
}