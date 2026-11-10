#include <iostream>
#include <treenode.cpp>
using namespace std;

// 这道题的核心思路：二叉搜索树的中序遍历一定是递增的
// 只要在中序遍历的过程中找第k个就可以
// 涉及到：中序遍历 + 计数

bool inorder(TreeNode* root, int k, int& ans, int& count){
    // 这里count也要加到参数里面，因为count会随着递增而变化
    // 这里返回bool类型，是为了体现遍历完成。
    // return true:代表了已经找到第k小的元素
    if(root==nullptr) return false;

    // 先遍历其左子树
    if(inorder(root->left, k, ans,count)){
        // 如果其左子树遍历完成，找到k,return true
        return true;
        // 这里为什么不能直接写：return inorder(root->left,k,ans,count)? 因为：程序到左子树还没有结束，还需看根节点和右子树。
        // 假如return false的话，程序直接中止了，不对。
    }
    // 再对于当前根节点操作
    count++;
    if(count==k){
        ans = root->val;
        return true;
    }
    // 最后遍历右子树
    return inorder(root->right,k,ans,count); // 这里是程序末尾了，可以直接return ，不影响递归过程。
}

int kthSmallest(TreeNode* root, int k){
    int ans = 0;
    int count = 0;
    inorder(root,k,ans,count);
    return ans;
}