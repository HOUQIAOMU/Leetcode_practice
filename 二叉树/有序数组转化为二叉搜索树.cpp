#include <iostream>
#include <treenode.cpp>
#include <vector>
using namespace std;

//[-10,-3,0,5,9] 0先作为root,然后再到[-10,-3]这一区间，-3作为root，[5.9]这一区间,9作为root
TreeNode* build(int left, int right, vector<int>&nums){
    // 构造left和right的中点作为root
    // 并且对于每个小区间，其实都是这样，递归进行
    if(left>right){
        // 递归终止条件
        return nullptr;
    }
    int mid = left + (right-left)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = build(left,mid-1,nums);
    root->right = build(mid+1,right,nums);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>&nums){
    return build(0,nums.size()-1,nums);
}