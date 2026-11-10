#include <iostream>
#include <listnode.h>

bool isBalindrome(ListNode* head){
    // 第一种思路，把每个元素push_back到vector里，然后去双指针判断

    // 第二种：快慢指针找链表中点，然后反转后半指针，判断是否相同
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;
        // 这样slow对应的就是中点
    }
    // 如果是奇数个，要让slow后移一个，判断时直接把中间单独的舍掉，没必要带上中间值进行比较
    if(fast != nullptr){
        slow = slow -> next;
    }
    // 翻转slow之后的链表
    ListNode * pA = slow;
    ListNode * temp = nullptr;
    while(pA != nullptr){
        ListNode * p_next = pA -> next;
        pA -> next = temp;
        temp = pA;
        pA = p_next;
    }
    ListNode * pB = head;
    pA = temp;
    // 比较pA,pB的val是否相同
    while(pA != nullptr){
        if(pA->val != pB->val){
            return false;
        }
        pA = pA -> next;
        pB = pB -> next;
    }
    return true;


}