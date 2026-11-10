#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int>&nums, int k){
    // 额外数组法
    int n = nums.size();

    if(n == 0){
        return;
    }
    vector<int>orin_nums;// 创建一个orin_num，存储原数字
    for(int i = 0; i < n; i++){
        orin_nums.push_back(nums[i]);
    }
    
    // 如果k>n，如数组只有4个元素，要轮转六步，那么要取余
    k = k%n;
    
    // 循环主体，赋新值,只有前k个和后k个是互换的
    for(int i = 0; i < n; i++){
        if(i < k){
            nums[i] = orin_nums[n-k+i];
        }
        else{
            nums[i] = orin_nums[i-k];
        }
    }
}
    //另一种方法：三次翻转法，仔细观察结果，就是先将整体数组翻转，然后再单独翻转前k个和后面剩下的
    void Rotate(vector<int>&nums, int k){
        int n = nums.size();
        if(n==0) return;
        k = k%n;
        // 先整体翻转
        reverse(nums.begin(), nums.end());
        // 再翻转前k部分
        reverse(nums.begin(), nums.begin()+k);
        // 再翻转后半部分
        reverse(nums.begin()+k, nums.end());
    }
    

