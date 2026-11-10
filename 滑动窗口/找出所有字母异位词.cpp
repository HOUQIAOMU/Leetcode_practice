#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findAnagrams(string s, string p){
    // 先用数组统计目标string p中的出现频率
    int exist_p[128] = {};
    for(int i = 0; i < p.size(); i++){
        exist_p[p[i]]++;
    }

    int n = p.size();
    vector<int> ans = {};
    // 循环要找的s
    int left = 0;
    int exist_s[128] = {};
    for(int right = 0; right < s.size(); right++){
        // exist_s[128]更新
        exist_s[s[right]]++;

        // 查看滑动窗口是否和p的大小是否相同
        // 如果窗口大了,那需要把left移除掉了
        if(right - left + 1 > p.size()){
            exist_s[s[left]]--;
            left++;
        }
        if(right - left + 1 == p.size()){
            // if(exist_p == exist_s){
            //     ans.push_back(left);
            // }
            // 数组不能直接比较
            bool same = true;
            for(int i = 0; i < 128; i++){
                if(exist_p[i] != exist_s[i]){
                    same = false;
                    break;
                }
            }
            if(same){
                ans.push_back(left);
            }
            
        }
    }
    return ans;

    
        

}
    
