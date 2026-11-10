#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> & matrix, int target){
    // 这个题的思路很巧妙：
    // 看右上角元素，因为右上角元素一定比左边大，又一定比同列的下面几个元素小，是个非常好的判断对象
    // 如果比较target和matrix[row][col],如果target更大，那么就row++,如果target更小，那么就col--
    int m = matrix.size();
    int n = matrix[0].size();
    int row = 0;
    int col = n - 1; //把要观察的列设为最右上角的元素
    bool succ_find = false;
    while(row < m && col >= 0){
        if(target == matrix[row][col]){
            succ_find = true;
            break;
        }
        else if(target > matrix[row][col]){
            row++;
        }
        else{
            col--;
        }
    }
    return succ_find;
    
    
}