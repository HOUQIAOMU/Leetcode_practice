// 移动零
#include <iostream>
#include <vector>
#include <algorithm>

void moveZeroes(std::vector<int> &nums){
    int slow = 0; //定义慢指针
    for(int i = 0; i < nums.size(); i++){
        // 先找到第一个0
        if(nums[i] == 0){
            // 将慢指针移动到第一个0处
            slow = i;
            for(int fast = i + 1; fast < nums.size(); fast++){
                // 定义快指针fast,去找下面的非0数字,如果非0,就和目前这个0所在的位置值交换
                if(nums[fast] != 0){
                    int temp = nums[slow];
                    nums[slow] = nums[fast];
                    nums[fast] = temp;
                    slow++; // 并把slow在的位置往前移动一位
                }
                else{
                    continue;
                }

            }
        }
        else{
            continue;
        }
    }

}

// 更主流，更快的做法：
// 只排非零数，这样自然而然把0挤到最后，而不操作0
void moveZero(std::vector<int> & nums){
    int slow = 0; // slow代表下一个非零数应该放的位置
    for(int fast = 0; fast < nums.size(); fast++){
        if(nums[fast] != 0){
            // 如果此数不为0,那么就把他移动到slow所在的位置，自然而然把0挤到最后
            std::swap(nums[fast], nums[slow]);
            slow++; // 然后把slow指针往后移动
        }
    }
}  