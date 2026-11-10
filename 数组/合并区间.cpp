#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals){
    // 如何判断两个区间是重叠的？、
    // 如a=[1,3]和b=[2,6]，可以看出，如果a[1]>b[0]，那么就有重叠
    // 但是如果[1,3]和[2,6]中间隔了一个[8,10]，那么就不能轻易判断了
    // 所以要先排序，然后再判断融合

    // 1.先排序，这类排序是默认按照首元素来的
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;

    // 再遍历
    for(const auto& interval : intervals){
        if(ans.empty()){
            // ans为空时，直接push进去
            ans.push_back(interval); 
        }
        if(ans.back()[1] < interval[0]){
            // ans的最大比当前interval要小，说明没有重叠
            ans.push_back(interval);
        }
        if(ans.back()[1] >= interval[0]){
            // 有重叠
            ans.back()[1] = max(ans.back()[1], interval[1]);
        }
    }
    return ans;

}