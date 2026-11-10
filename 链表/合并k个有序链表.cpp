// 合并k个有序链表
#include <iostream>
#include <vector>
#include <queue>
#include <listnode.h>
using namespace std;


//要利用队列维护各链表指向的节点
// 队列：队列元素，属于的集合，怎么比较；所以要先写一个比较器
struct cmp{
    // 内部是一个()的重载
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists){
    // 1.初始化，初始化一个queue；初始化虚拟头节点
    priority_queue<ListNode* , vector<ListNode*>, cmp>pq;
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    // 2. 把lists的每一个头节点放入到queue中
    for(ListNode* head : lists){
        if(head != nullptr){
            pq.push(head);
        }
    }
    // 3.不断取出最小的节点
    while(!pq.empty()){
        ListNode* cur = pq.top();
        pq.pop();
        tail->next = cur;
        tail = tail -> next;
        
        // 更新queue
        if(cur->next != nullptr){
            pq.push(cur->next);
        }
    }
    return dummy->next;


}

