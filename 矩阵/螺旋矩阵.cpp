#include <iostream>
#include <vector>
using namespace std;


vector<int> setZeroes(vector<vector<int>> & matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    int top = 0;
    int left = 0;
    int right = n - 1;
    int bottom = m - 1;
    vector<int> ans = {};
    while(top <= bottom && right >=left){
        // 左上到右上
        for(int j = left; j <= right; j++){
            ans.push_back(matrix[top][j]);
        }
        top++;

        // 右上到右下
        for(int i = top; i <=  bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        // 右下到左下
        // 这里需要额外判断一下还能不能走,还有没有底边可以走,因为这个条件是大循环才判断一次的，内部需要额外判断。
        // 例子有错时发现，属于corner case了
        if(top <= bottom){
            for(int j = right; j >= left; j--){
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        // 左下到左上
        if(left <= right){
            for(int i = bottom; i >= top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}