#include <iostream>
#include <listnode.h>

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    // 存放结果链表
    ListNode * dummy = new ListNode(0);
    ListNode * tail = dummy;
    // 进位量
    int carry = 0;
    
    //循环主体，算每一位
    while(l1 != nullptr || l2 != nullptr || carry != 0){
        // 循环结束条件：l1 = nullptr, l2 = nullptr, carry进位=0
        int x = (l1 != nullptr) ? l1->val: 0;
        int y = (l2 != nullptr) ? l2->val: 0;

        int sum = x + y + carry;
        int num = sum % 10; //num代表这一位置该有的数字
        tail -> next = new ListNode(num); // 这里没有现成链表地址，所以需要new一个
        tail = tail -> next;
        carry = sum / 10; // 更新进位

        // 链表向后移动
        if(l1 != nullptr){
            l1 = l1 -> next;
        }
        if(l2 != nullptr){
            l2 = l2 ->  next;
        }

    }
    return dummy -> next;


}