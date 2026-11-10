#include <iostream>
#include <vector>
#include <unordered_map>
#include <treenode.cpp>
using namespace std;
// 这道题的思路和子串里的和为k的子数组有点类似，利用“前缀和”来做
// 不过，相比数组操作，二叉树因为有分支，所以要涉及到dfs，以及回溯操作。
class solution{
    public:
        unordered_map<long long, int> prefix;
        int ans = 0;

        void dfs(TreeNode*root, int targetSum, int currentSum){
            if(root == nullptr) return;
            // 1.计算从根节点到当前节点的前缀和
            currentSum += root->val;
            ans += prefix[currentSum - targetSum];
            // 2.再把当前节点加入到哈希当中
            prefix[currentSum]++;
            // 3.递归搜索左子树和右子树
            dfs(root->left,targetSum,currentSum);
            dfs(root->right,targetSum,currentSum);
            // 4.把这一层的currentSum减掉。恢复到进入root前的状态
            prefix[currentSum]--;

        }

        int pathSum(TreeNode* root, int targetSum){
            prefix.clear();
            prefix[0] = 1;
            ans = 0;
            dfs(root,targetSum,0);
            return ans;
        }
};


