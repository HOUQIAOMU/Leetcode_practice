// 两数之和
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target){
    // 初始化一个哈希表
    std::unordered_map<int,int> visited_num;
    // 遍历nums
    for(int i = 0; i< nums.size(); i++){
        int find_target = target - nums[i];
        auto it = visited_num.find(find_target);
        if(it!= visited_num.end()){
            // 找到
            return std::vector<int>{i,it->second}; 
        }
        else{
            // 未找到
            visited_num.insert({nums[i],i});
        }
    }
    return std::vector<int>{};


}