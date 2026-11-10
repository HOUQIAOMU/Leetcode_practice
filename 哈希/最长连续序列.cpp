#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;


// 输入：[100,4,200,1,3,2]
// 输出：4

int longestConsecutive(vector<int> &nums){
    //initialize
    int max_length = 0;
    unordered_set<int> all_nums(nums.begin(),nums.end());// 这样直接将nums排序后放进哈希，还能去重

    // 这里一个细节：遍历哈希表效率更高。哈希可以自动去重，且不用排序。
    for(int num : all_nums){
        int first_find = num - 1;
        auto it = all_nums.find(first_find);
        if(it == all_nums.end()){
            // 目标：就是要找找不到num-1的元素
            // 找不到num-1，说明是一段的头，接下来去循环找num+1
            int cur_num = num;
            int length = 1;
            while(all_nums.find(cur_num + 1) != all_nums.end()){
                length++;
                cur_num++;
            }
            max_length = max(length, max_length);
            
    }
        else{
            continue;
        }
    }
    return max_length;
}