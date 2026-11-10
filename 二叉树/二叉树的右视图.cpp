#include <iostream>
#include <vector>
#include <treenode.cpp>
#include <queue>
using namespace std;

vector<int> rightSideView(TreeNode* root){
    // 核心：层序遍历,存入最右侧元素
    // 还是按层序遍历的结构来写，不过不用把所有元素都push到ans中,只要push每行最后一个
    vector<int> ans;
    if(root==nullptr) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int q_size = q.size();
        for(int i = 0; i < q_size; i++){
            TreeNode* node = q.front();
            q.pop(); // 弹栈
            
            // 判断当前节点是否是最右侧节点
            if(i == q_size-1){
                ans.push_back(node->val);
            }
            // 再把左右子树加入到队列中
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

        }
    }
    return ans;

    
}