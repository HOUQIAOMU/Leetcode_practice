#include <iostream>
#include <listnode.h>

ListNode* swapPairs(ListNode* head){
    // 循环交换
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    ListNode * prev = dummy;
    while(prev -> next != nullptr && prev -> next -> next != nullptr){
        // 内部两两交换,先标记first,second
        ListNode * first = prev -> next;
        ListNode * second = first -> next;
        // 开始交换,prev->a->b 转化成prev->b->a
        ListNode * next_target = second -> next;
        prev -> next = second;
        second->next = first;
        first->next = next_target;

        // 然后更新prev
        prev = first;
    }
    return dummy->next;
    // 链表的两两交换相对简单，不需要temp节点。只有回文链表才需要。这里直接制定地址就好
}