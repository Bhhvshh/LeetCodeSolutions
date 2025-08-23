class LRUCache {
public:
 unordered_map<int,int> umap;
 unordered_map<int,int> count;
 int cap;
 int size = 0;
 deque<int> q;

    LRUCache(int capacity) {
        cap = capacity;
        
    }
    
    int get(int key) {
        if(umap.find(key)==umap.end()) return -1;

        q.push_back(key);
        count[key]++;
        return umap[key];
        
    }
    
    void put(int key, int value) {
        
        if(count[key]++==0)size++;
        q.push_back(key);
        // count[key]++;
        
            while(size>cap){
                if(--count[q.front()]==0){size--; umap.erase(q.front());}
                q.pop_front();

            }
        
        umap[key]=value;

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */