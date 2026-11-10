#include <iostream>
#include <treenode.cpp>
using namespace std;

int maxDepth(TreeNode* root){
    // 要讲清楚这个过程：首先对于一个根来说：其深度等于depth(root)= 1+ max(左子树最大深度，右子树最大深度)
    // 也就是depth(root) = 1 + max(leftdepth,maxdepth)
    // 那么对于depth的左节点，要要这么计算，所以要进行递归
    // 分解型递归

    // 1.首先，如果root为空节点，那么其一定没有depth，直接返回
    if(root == nullptr) return 0;

    // 2.找左子树深度
    int leftdepth = maxDepth(root->left);
    // 3.找右子树深度
    int rightdepth = maxDepth(root->right);
    int result = 1 + max(leftdepth,rightdepth);
    return result;
}