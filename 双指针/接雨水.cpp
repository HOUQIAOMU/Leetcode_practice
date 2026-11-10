#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 要关心的是真正的墙，也就是leftmax和rightmax

int trap(vector<int> & height){
    int n = height.size();
    if (n == 0) return 0;

    // leftmax/rightmax 记录左右两侧已经遇到的最高柱子
    int leftmax = height[0];
    int rightmax = height[n - 1];
    int left = 0;
    int right = n - 1;
    int ans = 0;

    while(left < right){
        // 当前左右柱子的较矮者决定这一侧能接多少水
        if(height[left] < height[right]){
            // 谁矮谁先结算，因为取决于矮的这一侧，
            leftmax = max(leftmax, height[left]);
            ans += leftmax - height[left];
            left++;
        }
        else{
            rightmax = max(rightmax, height[right]);
            ans += rightmax - height[right];
            right--;
        }
    }
    return ans;
}