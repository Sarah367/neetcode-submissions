class Node {
    public:
        int key;
        int val;
        Node* prev = nullptr;
        Node* next = nullptr;
};
class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cacheMap;
    Node* left = new Node(0);
    Node* right = new Node(0);
    // left = LRU, right=most recent
    

    // remove from list
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    // insert node at the right
    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }
public:

    LRUCache(int capacity) {
        this->capacity = capacity;
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cacheMap.find(key) != cacheMap.end()) {
            remove(cacheMap[key]);
            insert(cacheMap[key]);
            return cacheMap[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            remove(cacheMap[key]);
        }
        Node* newNode = new Node(key, value);
        cacheMap[key] = newNode;
        insert(newNode);

        if (cacheMap.size() > capacity) {
            // remove the LRU from list and cache.
            Node* lru = left->next;
            remove(lru);
            cacheMap.erase(lru->key);
            delete lru;
        }
    }
};
