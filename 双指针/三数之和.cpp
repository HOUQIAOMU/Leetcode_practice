// 我想用双指针 → 双指针需要单调性 → 无序数组没有单调性 → 排序制造单调性。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 出错的例子：[1,2,0,1,0,0,0,0]
// 这个题小细节很多

vector<vector<int>> threeSum(vector<int> & nums){
    // 固定一个数字，找另外两个数的搭配
    // 固定后，利用双指针找另外两个数之和是否等于固定数的相反数，排序更合适
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans = {};
    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i-1]){
            // 先判断重不重复
            continue;
        }   
        int target = -nums[i];
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right){
            if(nums[left] + nums[right] > target){
                right--;
            }
            else if(nums[left] + nums[right] < target){
                left++;
            }
            else{
                ans.push_back({nums[i],nums[left], nums[right]});
                left++;
                right--;
                // 这里要去重，不能left++,right--后和刚才情况一样
                while(left < right && nums[left] == nums[left-1]){
                    left++;
                }
                while(left < right && nums[right] == nums[right+1]){
                    right--;
                }       
            }
        }
    }
             
    
    return ans;
} 