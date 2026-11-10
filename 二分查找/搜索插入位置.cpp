#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target){
    // 二分查找，很多细节
    int left = 0;
    int right = nums.size()-1;
    while(left<=right){
        int mid = left + (right - left)/2; // 这里这么写是为了防止二者数值相差过大
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            // 说明target在mid右侧
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return left;// 这里return left也是细节，如{1,3,4,5},target = 2的情况。
    
}