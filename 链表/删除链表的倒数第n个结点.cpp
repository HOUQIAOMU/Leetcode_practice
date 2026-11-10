#include <iostream>
#include <listnode.h>

ListNode* removeNthFromend(ListNode* head, int n){
    // 首先加一个dummy，这样方便头指针的操作
    ListNode * dummy = new ListNode(0);
    dummy -> next = head;

    // 最后效果：要slow 和fast之间隔n，相当于fast在最后，slow在倒数第n个的前一个，这样是最好的。
    // 也就是slow和fast隔了n。
    // 所以先让fast走n+1,然后fast和slow一起走，这样最好。
    ListNode * slow = dummy;
    ListNode * fast = dummy;
    for(int i = 0; i < n + 1; i++){
        // 让fast先走n+1
        fast = fast -> next;
    }
    while(fast != nullptr){
        fast = fast -> next;
        slow = slow -> next;
    }
    // 这时就要删除slow的下一个节点
    slow -> next = slow->next->next;
    return dummy -> next;

}
