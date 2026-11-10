#include <iostream>
#include <treenode.cpp>
using namespace std;

int ans = 0;
int maxDepth(TreeNode* root){
    if(root==nullptr) return 0;
    int leftmax = maxDepth(root->left);
    int rightmax = maxDepth(root->right);
    ans = max(ans, leftmax+rightmax); // 更新ans
    return 1 + max(leftmax,rightmax); // 这里为什么要return深度呢？因为还要正常算每个节点的深度，与ans进行比较。
    // 如果直接return ans,那么会在中间出现错误
}

int diameterOfBinaryTree(TreeNode* root){
    ans = 0;
    maxDepth(root);
    return ans;
}