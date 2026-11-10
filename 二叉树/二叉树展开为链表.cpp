#include <iostream>
#include <treenode.cpp>
using namespace std;

void flatten(TreeNode* root){
    // 核心思路：把每个节点的left变为right。暂存起来的right最后放到合适的位置
    if(root==nullptr) return ;
    // 先分别递归展开左右子树
    // 期望：进行左右操作之前，左右子树已经变为链表
    flatten(root->left);
    flatten(root->right);

    // 准备改变left和right关系
    TreeNode* right = root->right; //暂存
    root->right = root->left;
    root->left = nullptr;

    // 再去找合适的right摆放的位置
    TreeNode* q = root;
    while(q->right!=nullptr){
        q = q->right;
    } 
    q->right = right;
}