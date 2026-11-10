#include <iostream>
#include <listnode.h>

bool hasCycle(ListNode* head){
    // 有环意味着没有链表的next指向nullptr
    // 所以用快慢指针：如果有环，快慢指针一定会相遇。没环就直接到nullptr了
    ListNode * slow = head;
    ListNode * fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}