#include <iostream>
#include <treenode.cpp>
#include <vector>
#include <unordered_map>
using namespace std;
// 做了这些二叉树题目，感觉关键的切入点都可以从：其中的一棵树的操作来看
// 再去考虑，是否其他子树都可以拆分为一样的规律。

//preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
class Solution{
    unordered_map<int,int>index;// 查阅中序展开的序号
    TreeNode* build(vector<int>& preorder, int preleft,int preright, int inleft, int inright){
        // preleft:preorder里需求范围的左边界; preright：preorder里需求范围的右边界
        // inleft:inorder里需求范围的左边界，inright同理。

        // 1. 递归终止条件
        if(preleft>preright) return nullptr;
        // 2.首先，对于先序遍历，其第一个节点一定是其根节点,建立根节点
        int rootVal = preorder[preleft];
        TreeNode* root = new TreeNode(rootVal);
        // 3.查左子树->inorder里根节点左侧的元素
        // 所以先找根节点在哪里
        int k = index[rootVal];
        int leftsize = k - inleft;// 左子树的范围
        // 4.递归建立左子树
        root->left = build(preorder, preleft+1,preleft+leftsize,inleft,k-1);
        // 5.再递归建立右子树
        root->right = build(preorder, preleft+leftsize+1,preright, k+1, inright);
        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            index[inorder[i]] = i;
        }
        return build(preorder,0,n-1,0,n-1);
    }

};