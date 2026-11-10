#include <iostream>
#include <listnode.h>


ListNode * detectCycle(ListNode* head){
    // 数学推导：设链表头head到环入口的距离为a，从环入口到快慢指针相遇点的距离为b
    // 设链表中环的长度为c，fast绕环走了n圈
    // slow指针从头走到相遇点走了:a + b；fast指针从头走到相遇点走了a + b + n*c;fast速度是slow的2倍
    // 所以有：2(a + b) = a + b + n*c;
    // 化简得：a = n*c - b;
    // 式子左项a为：slow pointer走到环起点的位置
    // 式子右项为：fast pointer从相遇点走到环起点的位置
    // 所以只要让这两项相等，就能找到环起点
    // 数学，太巧妙了


    // 先找相遇点
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            break; // 在相遇时结束
        }
    }
    // 如果没有环
    if(fast == nullptr || fast->next == nullptr){
        return nullptr;
    }
    // 提取相遇节点
    ListNode* pA = head;
    ListNode* pB = slow;
    while(pA != pB){
        pA = pA -> next;
        pB = pB -> next;
    }
    return pA;
    
}