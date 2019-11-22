#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<iterator>
using namespace std;
//tracker可改用链表结构
class LRUCache {
private:
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> tracker;
    int capacity;
    void processPriority(int key){
        tracker.erase(cache[key].second);
        tracker.push_back(key);
        cache[key].second=--tracker.end();
    }
public:
    int count;
    LRUCache(int capacity) {
        this->capacity=capacity;
        this->count=0;
    }
    
    int get(int key) {
        if (capacity==0 || cache.find(key) == cache.end()) return -1;
        processPriority(key);
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(capacity==0){
            return;
        }
        if(get(key)==-1){
            if(tracker.size()==capacity){
                cache.erase(tracker.front());
                tracker.pop_front();
            }
            tracker.push_back(key);
            cache[key].first = value;
            cache[key].second = --tracker.end();
        }else{
            cache[key].first=value;
            processPriority(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */