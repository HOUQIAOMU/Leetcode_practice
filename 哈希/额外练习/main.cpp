#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void printUAVtimes(const std::unordered_map<std::string, int> uav_count){
    for(auto &entry : uav_count){
        std::cout<<entry.first<<" : "<<entry.second<<std::endl;
    }
}

std::string maxUAVcount(const std::unordered_map <std::string,int> uav_count){
    int max_times = 0;
    std::string max_times_uav;
    for(auto it : uav_count){
        if(it.second > max_times){
            max_times = it.second;
            max_times_uav = it.first;
        }
        else if(it.second == max_times){
            // 如果次数相同怎么处理
            max_times_uav = max_times_uav + " and " + it.first;
        }
        else{
            continue;
        }
    }

    return max_times_uav;
}

void printStatus_times(const std::unordered_map<std::string, int> status_count){
    for(auto &entry : status_count){
        std::cout<<entry.first<<" : "<<entry.second<<std::endl;
    }
}

void find_return_uav(std::unordered_set <std::string> return_set){
    std::cout<<"returned_uav:"<<std::endl;
    for(const auto & return_uav : return_set){
        std::cout<<return_uav<<std::endl;
    }
    
}




int main(){
    // 首先确认输入日志，并能做到正确读取日志
    int n = 0;// 日志条目数量
    std::cin>>n;
    std::cout<<std::endl;
    // 初始化一个哈希表，存放无人机名称以及其出现的次数
    std::unordered_map <std::string,int> uav_count;
    std::unordered_map <std::string,int> status_count;
    std::unordered_set <std::string> return_set;

    for(int i = 0; i < n; i++){
        std::string id;
        std::string status;
        std::cin >> id >> status;
        // 将信息存储到三个哈希中
        uav_count[id]++; // 将id存入uav_count哈希
        
        status_count[status]++; 
        
        if(status == "return" || status == "RETURN" || status == "Return"){
            return_set.insert(id);
        }

        
    }

    std::cout<<"------日志分析-----"<<std::endl;
    // 1.输出无人机对应的出现次数
    printUAVtimes(uav_count);
    std::cout<<"--------------"<<std::endl;
    // 2.输出出现最多次的无人机
    std::string max_count_uav = maxUAVcount(uav_count);
    std::cout<<"出现次数最多的无人机为："<<max_count_uav<<std::endl;
    std::cout<<"--------------"<<std::endl;
    // 3.输出每种状态出现的次数
    printStatus_times(status_count);
    std::cout<<"--------------"<<std::endl;
    // 4.输出返回的uav
    find_return_uav(return_set);
    


    return 0;
}