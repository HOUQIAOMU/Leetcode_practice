#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums){
    int n = nums.size();
    // nums[i]所对应位置的乘积：left[i]*right[i]
    // 也就是左侧元素的乘积和有测元素的乘积
    vector<int> left(n,1);// 初始化为1,因为令left[0] = 1
    vector<int> right(n,1);
    vector<int> ans(n,1);

    // 计算左侧乘积
    for(int i = 1; i <n; i++){
        left[i] = left[i-1] * nums[i-1]; //递推关系
    }
    // 计算右侧乘积
    for(int i = n-2; i>=0; i--){
        right[i] = right[i+1]*nums[i+1];
    }
    // 合并左右乘积
    for(int i = 0; i < n; i++){
        ans[i] = left[i]*right[i];
    }
    return ans;
}