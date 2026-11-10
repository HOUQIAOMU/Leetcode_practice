#include <iostream>
#include <unordered_map>

// 怎样去设计一个class?
// 先想需求，这个LRUCache需要的操作：初始化Cache池，get缓存key对应的value，put进去key和value。
// 同时还要检查是否满capacity,满了删除最久没有操作的。
// 所以，会对外涉及到三个函数，以及其对应的接口，先写出来
// 接着，key和value，一下子就想到了哈希unordered_map，这里还需要延伸思考哈希对应的两种类型应该是什么？
// 然后检查使用顺序，可以考虑用链表，把最不经常用的key对应的node放在链表尾，直接删掉，所以还需要一个数据结构为链表node。
// 这样private和public的大致框架就可以先出来

// 接着就是设计详细的数据结构内部内容以及函数接口、参数
// 设计的时候，要从需求去反推数据结构
// 仅有哈希是不够的，因为哈希没法维护加入的时间，所以还需要额外引入链表
class LRUCache{
    private:
        struct Node{
            int key; // 需要通过key来表示这个是哪个key的Node
            int value;
            Node* prev;
            Node* next; // prev和next表示：当前节点的上一个元素指向和下一个元素指向。
            // 这里同时设计了prev和next，便于操作
            Node(int x=0, int y=0):key(x),value(y),prev(nullptr),next(nullptr){};
        };
        std::unordered_map<int, Node*> mp; // 这里设计的int对应的是Node*
        int capacity;
        //head和tail指针用于双向链表的操作
        Node* head;  // head->next是链表第一个元素
        Node* tail;  // tail->prev是链表最后一个元素

        // 下面是后面get 和 push可能会用到的内部函数，这里进行声明。
        void removeNode(Node* node);
        void addTohead(Node* node);
        void moveTohead(Node* node);

    public:
        LRUCache(int capacity){
            // 先实现构造函数
            this -> capacity = capacity;
            head = new Node(0);
            tail = new Node(0);
            
            // 初始化状态
            head -> next = tail;
            tail -> prev = head;
            
        }
        ~LRUCache(){
            delete head;
            delete tail;
        }

        int get(int key){
            // 如果key存在，返回其对应的value;不存在，则返回-1
            if(mp.find(key) == mp.end()){
                return -1;
            }
            
            Node* node = mp[key]; // 先把这个节点调出来
            // 刚访问过，把此节点移动到head
            moveTohead(node);
            return node->value;
            

        }

        void put(int key, int value){
            // 把一对key 和 value放入到LRUCache中，也就是加入到node中

            // 如果key存在，那么更新value，并move2head
            if(mp.find(key) != mp.end()){
                Node* node = mp[key];
                moveTohead(node);
                node->value = value;
                return;
            }

            // 如果key不存在，加入进去，但要注意capacity
            Node* node = new Node(key, value); // new一个Node
            mp[key] = node; // 加入到哈希表中
            addTohead(node); // 因为是新添加的，加到头部

            // 加了之后，如果capacity多了
            if(mp.size() > capacity){
                // 删掉最后的元素
                Node* del = tail -> prev;
                removeNode(del);
                // 还要从哈希中删除
                mp.erase(del->key);
                delete del;
            }


        }

};
void LRUCache::addTohead(Node* node){
    // 把node加到head
    // 双向链表的prev,next都要维护，双向链表
    Node* p_next = head -> next;
    node -> prev = head;
    node -> next = p_next;
    p_next -> prev = node;
    head -> next = node;
    
}

void LRUCache::removeNode(Node* node){
    // 把node节点删掉
    // A->B->C 变成A->C
    // 同样也需要维护双向链表
    Node* p_prev = node -> prev;
    Node* p_next = node -> next;
    p_prev -> next = p_next; 
    p_next -> prev = p_prev;

}

void LRUCache::moveTohead(Node* node){
    // 把node节点移动到头节点
    // 需要先remove，再add
    removeNode(node);
    addTohead(node);
}