#include <iostream>
#include <listnode.h>

// 这道题的思路：将一个链表分成两半，然后将这两个链表进行：合并两个有序链表。这样，就实现了一个重新排序的链表

// 先把合并两个有序链表复习写上
ListNode* mergeList(ListNode* head1, ListNode* head2){
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy; // 新建的链表指针cur

    while(head1 != nullptr && head2 != nullptr){
        if(head1 -> val < head2 -> val){
            cur -> next = head1;
            head1 = head1 -> next;
        }
        else{
            cur -> next = head2;
            head2 = head2 -> next;
        }
        cur = cur -> next;
    }
    // 循环结束后，把剩下的接上去
    if(head1 != nullptr){
        cur -> next = head1;
    }
    if(head2 != nullptr){
        cur -> next = head2;
    }
    return dummy -> next;
}

// 遇到的问题：fast快指针要是head->next
ListNode* sortList(ListNode* head){
    // 1.先鲁棒性判断,0个节点或1个节点，则本身有序
    if(head == nullptr || head-> next == nullptr){
        return head;
    }

    // 2.快慢指针找中点
    ListNode* slow = head;
    ListNode* fast = head -> next; // 这里细节，fast要是head->next,这样才能保证分割的链表数量一致
    // 如果都是head的话，对于1->2这样的链表，那就slow = 2了，那么head2测就为空链表，导致递归死循环。
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    // 找到中点后断开
    ListNode* head2 = slow->next; //head2为右侧链表头
    slow->next = nullptr; //再把左侧链表断掉

    // 递归进行拆分排序，这个递归的过程有点难想
    // 这里的递归就是为了：得到有序链表，本身拆分后的链表是无序的，想要借助合并有序链表，则必须将其整理成无序。
    ListNode* head1 = sortList(head);
    head2 = sortList(head2);
    // 例:4->2->1->3
    /*图示：
                    4 2 1 3
                   /       \
                 4 2       1 3
                /   \     /   \
               4     2   1     3
                \   /     \   /
                 2 4       1 3
                    \     /
                     1 2 3 4
    从浅到深，从右到左
    */
   // 1.在刚才的代码中，已被拆分成：head->4->2和 head2->1->3。
   // 先执行sortList(head),即在这次中，拆分为head->4和head2->2，最深层sortlist结束
   // 回到中间层sortlist,再head1 = sortList(head),这次直接return了4节点，然后下一行代码head2 = sortlist(head2)，return了2节点。
   // 此时过程回到中间层sortlist的最行一行，return了mergeList(head1, head2)，即return了dummy -> 2 -> 4
   // 结束后，代码过程回到了最上层的head2 = sortList(head2)这一行，再对head2->1->3进行了同样层次的递归操作，最终这行代码return了dummy->1->3
   // 走到最上层的最后一行，return dummy->1->2->3->4结束。

    return mergeList(head1, head2);

}