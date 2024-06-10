class LRUCache {
private:
    int time;
    int cap;
    unordered_map<int, int> kvMap;
    unordered_map<int, int> ktMap;
    
public:
    LRUCache(int capacity) {
        time = 0;
        cap = capacity;
    }
    
    // O(1)
    int get(int key) {
        if (kvMap.find(key) == kvMap.end()) return -1;
        
        ktMap[key] = time++;
        return kvMap[key];
    }
    
    // O(capacity)
    void put(int key, int value) {
        // If the key already exist, just update.
        // Evict only if: size = capacity AND key not present.
        if (kvMap.find(key) == kvMap.end() && kvMap.size() == cap) {
            int minTime = INT_MAX, minKey;
            for(auto it = ktMap.begin(); it != ktMap.end(); ++it) {
                if (it->second < minTime) {
                    minTime = it->second;
                    minKey = it->first;
                }
            }
            kvMap.erase(minKey);
            ktMap.erase(minKey);
        }
        
        kvMap[key] = value;
        ktMap[key] = time++;
    }
};