#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> & height){
    // 一个放最左侧，一个放最右侧，然后按短边进行计算。
    // 大小只取决于最短边
    int left = 0;
    int right = height.size() - 1;
    int ans = 0;
    while(left < right){
        if(height[left] <= height[right]){
            int area = (right - left) * height[left];
            ans = max(ans, area);
            left++;
        }
        else{
            int area = (right - left) * height[right];
            ans = max(ans, area);
            right --;
        }
    }
    return ans;
}