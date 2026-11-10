#include <iostream>
#include <treenode.cpp>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root){
    // 层序遍历：广度优先思想，结合二叉树和队列。
    // 循环进行：利用队列先进先出机制，弹出front()，ans里push进其val;然后再把其左节点和右节点入队
    vector<vector<int>> ans;
    if(root==nullptr) return ans;

    // 创建队列，
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        // 只要队列非空就始终进行
        // 每次循环负责的是一层
        int q_size = q.size();
        vector<int> level; //记录这一层的元素
        for(int i = 0; i<q_size; i++){
            TreeNode* node = q.front();
            level.push_back(node->val);
            q.pop();

            // 再把node的左和右节点入队
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }

        }
        ans.push_back(level);
    }
    return ans;

}