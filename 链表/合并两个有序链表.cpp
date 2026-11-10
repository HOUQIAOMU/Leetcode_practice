#include <iostream>
#include <listnode.h>

ListNode * mergeTwoLists(ListNode* list1, ListNode* list2){
    ListNode* p1 = list1;
    ListNode* p2 = list2;
    
    // 建立一个虚拟头节点dummy,便于找到tail的位置
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy; // tail指向合并链表的最后一个节点

    while(p1 != nullptr && p2 != nullptr){
        if(p1 -> val <= p2 -> val){
            // p1更小
            tail -> next = p1;

            // 更新后p1后移
            p1 = p1 -> next;
        }
        else{
            tail -> next = p2;
            p2 = p2 -> next;
        }
        // tail有值后，tail也要后移动
        tail = tail -> next;
    }
    // 当p1或者p2是nullptr时，说明有一个走完，剩下的正常插入就可以
    if(p1 != nullptr){
        tail -> next = p1;// 不需要循环，因为p1后面直接承载了之后的地址
    }
    else{
        tail -> next = p2;
    }
    // 返回的是虚拟链表头的next节点
    return dummy -> next;

}