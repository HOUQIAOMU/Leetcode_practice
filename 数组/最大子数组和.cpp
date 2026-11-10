#include <iostream>
#include <vector>
using namespace std;

int maxSubarray(vector<int>& nums){
    // 这道题的核心思想：动态规划
    // 当判断到一个数的时候，如果前面几个数的和加上这个数，还没有这个数自己大
    // 那么前面几数之和完全可以不要
    // 核心状态转移方程：dp[i] = max(dp[i-1]+num[i], num[i])
    
    // 初始化
    int n = nums.size();
    vector<int>dp(n); // 初始化一个大小为n的vector
    dp[0] = nums[0]; // 这里是为了下面循环可以从i=1开始，以防越界
    int ans = dp[0];

    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i-1]+nums[i],nums[i]);
        ans = max(ans, dp[i]);
    }
    return ans;
    // 其实我最后的思路，是找dp[i]里的最大值，那么就应该像下面这么写
    // ans = *max_element(dp.begin(),dp.end());
}
    
int maxSubarray_2(vector<int>& nums){
    // 从这个疑问延伸下去：我可以不从dp[i]里找最大值，我只需要找ans和当前dp[i]的最大值即可
    // 而dp[i]只和dp[i-1]有关，那我为什么要记录dp[i]呢？我直接用一个变量存储dp[i-1]不就完了吗？
    // 这样空间复杂度还更低
    // 初始化
    int curSum = nums[0];
    int ans = nums[0];
    for(int i = 1; i < nums.size(); i++){
        curSum = max(curSum+nums[i], nums[i]);
        ans = max(ans,curSum);
    }
    return ans;
}
    
    
