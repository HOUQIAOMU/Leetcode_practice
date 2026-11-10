#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s){
    int left = 0;
    // 用一个哈希来表示滑动窗口？
    unordered_set<char> window;
    int max_size = 0;
    for(int i = 0;i < s.size();i++){
        while(window.count(s[i])){
            // 子串内有重复情况
            window.erase(s[left]); // 删除s[left]
            left++;
        }
        // 如果没有重复情况
        window.insert(s[i]);
        max_size = max((int)window.size(), max_size);
        
    }
    return max_size;
}

// 还可以不用哈希来写,因为哈希开销比较大,可以用一个数组来表示是否存在
// 数组更快
int lengthOfLongestSubstring2(string s){
    int left = 0;
    int right = 0;
    bool exist[128] = {}; //用一个数组表示128个字母的存在情况
    int ans = 0;
    for(right = 0; right < s.size(); right++){
        while(exist[s[right]]){
            // 在滑动窗口中存在
            exist[s[left]] = false;
            left++;
        }
        // 如果在滑动窗口中不存在
        exist[s[right]] = true;
        ans = max(ans, right - left + 1); // 可以直接用区间距离来表示窗口大小
    }
    return ans;
}