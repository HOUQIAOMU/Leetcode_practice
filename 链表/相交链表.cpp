#include <iostream>
#include <listnode.h>

ListNode* getIntersectionNode(ListNode * headA, ListNode * headB){
    // 核心思路：正常来说，如果a链表长度是4,b链表长度是5,那么让b先走一个，然后两个链表一起走到下一个节点，地址相同就有相交
    // 那么如果让两个链表都走4+5个长度，a走完走到b上，b走完走到a上，那么二者路径长度就会相同。
    ListNode * pA = headA;
    ListNode * pB = headB;

    while(pA != pB){
        if(pA == nullptr){
            pA = headB;
        }
        else{
            pA = pA -> next;
        }
        if(pB == nullptr){
            pB = headA;
        }
        else{
            pB = pB -> next;
        }
        // 即便没有交点，最后也会pA = pB = nullptr，从而跳出循环
    }
    return pA;
    
}