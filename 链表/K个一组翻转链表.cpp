#include <iostream>
#include <listnode.h>

ListNode * reverseKGroup(ListNode* head, int k){
    // 先按照两两翻转链表的经验，建立链表头
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;

    // 这个得用一个例子：dummy->1->2->3->4->5，假设k = 3
    ListNode* groupprev = dummy;
    while(true){
        // 定义第k个节点，并找到这一组的k个节点
        ListNode* kth = groupprev;
        for(int i = 0; i < k; i++){
            kth = kth -> next;
            if(kth == nullptr){
                return dummy->next; //这时候找不到了，可以return了
            }
        }
        // 现在groupprev指向dummy，kth指向3
        // 先把下一组的开头保存下来，做一个限位
        ListNode* groupnext = kth -> next; // groupnext指向4

        // 现在可以进行翻转了，通过prev和cur和next
        ListNode* prev = groupnext; // 让prev直接指向4
        ListNode* cur = groupprev -> next;
        while(cur != groupnext){
            ListNode* next = cur->next; // 先把这个提出来，要不然后面会发生变化，导致没法继续循环出错
            cur -> next = prev;//对于cur = 1时，让其next为4
            prev = cur; // 更新prev，让其变成1
            cur = next; //cur移动
            // 后面的循环，cur = 2, 让2的next变为1,prev更新为2.
            // 循环下去，很合理。
        }
        // 翻转过后，groupprev还指向的是1,应该让开头指向3了
        // 但是同时，groupprev也要继续往前走，这样才能保证group区间的正确
        // 所以要先把目前groupprev的next存下来，目前groupprev的指向，正好就应该是它下一步在的地方
        ListNode* oldgroupstart = groupprev -> next; // 这里指向的还是1呢，但是此时1已经变成4后面了，所以就存下了这个位置
        groupprev -> next = kth; //kth现在被翻转到最前面了，所以让groupprev(第一次循环时，也就是dummy，指向最前面的kth)

        // 再更新groupprev
        groupprev = oldgroupstart;

        // 以此往复，这个过程好复杂。
        // 需要画一个图，这道题再多做几遍，才能完全理解
    }
}