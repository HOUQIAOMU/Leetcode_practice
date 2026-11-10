#include <iostream>
#include <listnode.h>

ListNode * reverseList(ListNode * head){
    ListNode* pA = head;
    ListNode* p_temp = nullptr;
    while(pA != nullptr){
        // 借助中间变量，实现倒转
        // 还得先把原来的pA -> next保存下来
        ListNode* p_next = pA -> next;
        pA -> next = p_temp; // 借助中间变量，让1指向nullptr,2指向1,3指向2...
        p_temp = pA;
        pA = p_next;       
    }
    return p_temp; // 注意这里要return p_temp。如果return pA,那么return的是nullptr
}


ListNode* reverseList(ListNode* head){
    // 这个新版代码的变量命名更清晰一些
    // 实际就是prev, cur,next的更新
    ListNode* cur = head;
    ListNode* prev = nullptr; 
    while(cur != nullptr){
        // 先把此节点原本的next存储起来
        ListNode* p_next = cur->next;
        
        // 进行链表翻转
        cur -> next = prev;
        
        // 更新后，更新prev和cur
        prev = cur;
        cur = p_next;
    }
    return prev; // 最后一轮循环时，cur更新为了nullptr，所以要返回prev
}