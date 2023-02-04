/*
LRU replaces the line in the cache that has been in the cache the longest with no reference to it. 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Node {    
public: 
    int key, value;
    Node* next = NULL  ;
    Node* prev = NULL;
    Node() {}
    Node(int key, int value): key(key), value(value) {}
};

class LinkedList {
public: 
    Node* head;
    Node* tail;
    LinkedList() { head = NULL; tail = NULL;}
    void add_to_head(Node* item) {
        if (head != NULL){
            item->next = head;
            head->prev = item;
        }
        if (tail == NULL) tail = item;
        head = item;
    }
    void unlink(Node* item) {
        if (item == NULL) return;
        Node* prev_item = item->prev;
        Node* next_item = item->next;
        if (prev_item != NULL) prev_item->next = next_item;
        if (next_item != NULL) next_item->prev = prev_item;
        if (head == item) head = next_item;
        if (tail == item) tail = prev_item;
        item->prev = NULL;
        item->next = NULL;
    }
};


class LRUCache {
    map<int, Node*> cache_map;
    LinkedList*  history = new LinkedList();
    int capacity;
    

public:
    LRUCache(int capacity): capacity(capacity) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    }

    void _evict_least_recent_item(){
        Node* lru_item = history->tail;
        if (lru_item == NULL) return;
        _remove(lru_item);

    }

    void _remove(Node* item){
        history->unlink(item);
        cache_map.erase(item->key);
    }

    int get(int key) {
        if (!cache_map.count(key)) return -1;
        Node* value_node = cache_map[key];

        if (history->head != value_node){
            history->unlink(value_node);
            history->add_to_head(value_node);
        }
        return value_node->value;
    }
    
    void put(int key, int value) {
        Node* value_node = new Node(key, value);
        if (cache_map.count(key)) _remove(cache_map[key]);
        if (cache_map.size() >= capacity) _evict_least_recent_item();
        history->add_to_head(value_node);
        cache_map[key] = value_node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



/*-------------------SOLUTION USING DEQUE O(N)--------------------------*/

// #include <deque>

// class LRUCache {
// public:
//     map<int, int> cache;
//     deque<int> dq;
//     vector<int> vc; 
//     int capacity;
//     LRUCache(int capacity): capacity(capacity) {
//         ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
//     }
//     int _remove(int x){
//         /* remove element x from deque dq. return 0 if not found */
//         auto it = find(dq.begin(), dq.end(), x);
//         if (it != dq.end()){
//             dq.erase(it);
//             return 1;
//         }
//         return 0;
//     }

//     int get(int key) {
//         if (_remove(key)) dq.push_back(key); // reference key 
//         if (cache.count(key)) return cache[key];
//         return -1;
//     }
    
//     void put(int key, int value) {
//         if (dq.size() == capacity && !cache.count(key)){
//             int ref = dq.front();
//             dq.pop_front();
//             cache.erase(ref);
//         }
//         _remove(key);
//         cache[key] = value;
//         dq.push_back(key);
//     }
// };

