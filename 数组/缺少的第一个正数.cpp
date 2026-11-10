#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int firstMissingPositive(vector<int>& nums){
    int ans = 1;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        // 排序后的小于0的数，直接跳过
        if(i<=0) continue;

        // 判断是否有1,如果有1,那么ans自增，判断有没有2
        if(nums[i]==ans){
            ans++;
        }
        else if(nums[i] > ans){
            return ans;
            // 这里的条件是nums[i]>ans,是为了防止重复元素，如[0,1,1,2,2]
            // 刚进入1的时候，ans增加为2；第2个1，不符合任何条件，直接跳过；到第一个2这里的循环，ans增加为2；第2个2,也直接跳过。
            // 如果是到[0,1,1,2,3]，那么到3的时候，一定比ans=2大了，就直接返回ans
        }

    }
    return ans;
}


// 第二种主流的更复杂的方法
int FirstMissingPositive(vector<int>& nums){
    int n = nums.size();
    // 我只要考虑n以内的数字,即n=4时，那么一定就是缺1,2,3,4,5其中的一个
    for(int i = 0; i < n; i++){
        while(nums[i]<=0 && nums[i]>n && nums[nums[i]-1] != nums[i]){
            // 最后一种，防重叠，如[2,2,1]
            swap(nums[i],nums[nums[i]-1]); // 把nums[i]放在它应该在的地方->nums[nums[i]-1]
            // 也就是nums[i]=2，应该放在nums[1]处
        }
    }
    // 现在去寻找未被操作，未归位的数字
    for(int i = 0; i < n; i++){
        if(nums[i] != i+1){
            return i+1;
        }
    }

    // 如果n以内都在，那么就返回n+1
    return n+1;
}