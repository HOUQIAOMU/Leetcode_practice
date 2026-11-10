#include <iostream>
#include <vector>
using namespace std;


void setZeroes(vector<vector<int>> & matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    bool first_row_have_zero = false;
    bool first_col_have_zero = false;
    // 先判断第一行和第一列有没有0
    for(int i = 0; i < n; i++){
        if(matrix[0][i] == 0){
            first_row_have_zero = true;
            break;
        }
    }
    for(int j = 0; j < m; j++){
        if(matrix[j][0] == 0){
            first_col_have_zero = true;
            break;
        }
    }

    // 遍历矩阵，找0,如果找到，利用第一行和第一列元素作标记
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    // 根据标记，将此行/列都变为0
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[0][j] == 0 || matrix[i][0] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    // 如果第一行/第一列有0,把所在的这一行/列变0
    if(first_row_have_zero){
        // 第一行有0,把这一行都变成0,列在主程序里处理过
        for(int i = 0; i < n; i++){
            matrix[0][i] = 0;
        }
    }
    if(first_col_have_zero){
        // 第一行有0,把这一行都变成0,列在主程序里处理过
        for(int j = 0; j < m; j++){
            matrix[j][0] = 0;
        }
    }
}
