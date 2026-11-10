#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>> & matrix){
    // 思路：很巧妙，观察矩阵，对矩阵先转置再逐行反转(reverse)
    // 先转置
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i = 0; i < m; i++){
        for(int j = i+1; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // 再逐行reverse
    for(int i = 0; i < m; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}