#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 一道好难的hard题目
// 这道题是目前刷过的hard里面最难的一道题目
string minWindow(string s, string t){
    // 1. 初始化，初始化当前滑动窗口有几个需要的字母，以及要求t里面需要的字母
    unordered_map<char,int>window;
    unordered_map<char,int>need;
    for(char c:t){
        need[c]++;
    }
    // 2.初始化滑动窗口
    int left = 0;
    int right = 0;
    // 初始化满足字符串种类数量的变量valid
    int valid = 0;
    // 初始化最短子串
    int start = 0;
    int minLen = __INT_MAX__;

    // 主循环，不断扩大窗口
    while(right < s.size()){
        char c = s[right];
        right++;
        // 遍历到了c，就要更新窗口内的字符数量。如果不是要求的字符不管，是再更新
        if(need.count(c)){
            window[c]++;
            // 记录后看和need里面的这个字母对应的数量是否一致，如果一致，就可以加valid了
            if(window[c] == need[c]){
                valid++;
            }
        }
        // 当valid满足need要求时，尝试去缩小子串，即去掉最左侧的需要的元素（滑动窗口思想）
        while(valid == need.size()){
            // 如果这个子串更短，那么先把最短子串更新上，并记录start
            if(right-left < minLen){
                // 这里不直接用min是因为要记录start，比minLen大的子串的left不用记录下来赋给start
                minLen = right - left;
                start = left;
            }
            // 移除left
            char d = s[left];
            left++;
            if(need.count(d)){
                // 如果s[left]是need里面的元素
                if(window[d]==need[d]){
                    // 如果window里的d和need里的d次数相同，那么移除之后，就要减小valid了
                    // 如果不等于，说明还不够，这个字母对应的valid还没有加上去
                    // 所以要先判断这个
                    valid--;
                }
                window[d]--;
            }

            
        }
    }
    // 最后返回结果
    if(minLen == __INT_MAX__){
        return "";
    }
    return s.substr(start,minLen);
}
