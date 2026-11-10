#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k){
    // 这里运用了一个很绕的机制：前缀和。
    // 对于{1,2,3,4},通过哈希构造前缀和{1,3,6,10}.如对于k = 4,去查找当前sum - 4这一值，之前出没出现过。哈希表也存储了其出现过的次数
    unordered_map<int,int>mp;
    int sum = 0;
    int ans = 0;
    mp[0] = 1;// 防止第一个元素就是k，所以要初始化mp[0] = 1
    for(int i = 0; i < nums.size(); i++){
        // 先更新sum
        sum += nums[i];
        // 然后找sum-k有没有在mp里存在过
        if(mp.find(sum - k) != mp.end()){
            // 如果找到
            ans += mp[sum-k];
        }
        mp[sum]++;
    }
    return ans;
    
}