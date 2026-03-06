/*题目：
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。*/

/*思路：使用哈希表和双向链表来实现LRU缓存。哈希表用于快速查找，双向链表用于维护访问顺序。*/

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


 #include <iostream>
 #include <unordered_map>
 using namespace std;

 struct DLinkedNode {
    int key,value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode():key(0),value(0),prev(nullptr),next(nullptr){}
    DLinkedNode(int _key,int _value):key(_key),value(_value),prev(nullptr),next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity):capacity(_capacity),size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!cache.count(key))
            return -1;
        DLinkedNode *node = cache[key];
        moveToHead(node);
        return node -> value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            DLinkedNode* node =new DLinkedNode(key,value);
            cache[key]= node;
            addToHead(node);
            ++size;
            if(size > capacity){
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        }
        else{
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node){
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail(){
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};

int main(){
    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    cout << cache.get(1) << endl;
    cache.put(3,3);
    cout << cache.get(2) << endl;
    cache.put(4,4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;
    return 0;
}