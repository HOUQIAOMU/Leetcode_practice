#include <iostream>
#include <listnode.h>
#include <unordered_map>

class Node{
    public:
        int val;
        Node* next;
        Node* random;

    Node(int _val){
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

Node* copyRandomList(Node* head){
    if(head == nullptr){
        return nullptr;
    }

    // 用一个哈希表存储起原node节点和新的复制出来的链表的练习
    std::unordered_map<Node*, Node*> mp;
    // 第一次循环，先创建所有新节点
    Node* cur = head;
    while(cur != nullptr){
        mp[cur] = new Node(cur->val);
        cur = cur -> next;
    }
    // 第二次循环，建立next和random的关系
    cur = head;
    while(cur != nullptr){
        mp[cur]->next = mp[cur->next]; // mp[cur->next]对应着复制之后的node,如B'
        mp[cur]->random = mp[cur->random];
        cur = cur -> next;
    }
    return mp[head];
    
}