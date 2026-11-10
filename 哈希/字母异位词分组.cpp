#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
// input : vector<int>& strs:['eat' 'tea' 'bat']
// output: vector<vector<int>> [['eat','tea'],['bat']]
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs){
    //初始化
    vector<vector<string>> ans = {};//初始化一个ans
    unordered_map<string,int> visited_word;//哈希表：记录表中经过排序后的词，以及其对应的在ans中的位置

    //循环
    for(int i = 0; i < strs.size(); i++){
        // 先保留原词
        string initial_word = strs[i];
        // 对当前词排序
        sort(strs[i].begin(), strs[i].end());
        // 查找排序后的词aet,abt在哈希中是否存在
        auto it = visited_word.find(strs[i]);
        if(it == visited_word.end()){
            // 不存在，添加到哈希中，并记录目前其加入ans的位置,如果是不同字母组成的，位置正好是对应的ans.size()
            // 如eat加入到ans[0],加入后size变为1,后续bat再加入时，正好加入ans[1]位置
            int location = ans.size();
            visited_word.insert({strs[i],location});
            // 加入到ans中
            ans.push_back(vector<string>{initial_word});
        }
        else{
            // 如果找到了
            ans[it->second].push_back(initial_word);
        }
    }
    return ans;

}