class LRUCache {
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k, int value) {
            key = k;
            val = value;
            next = nullptr;
            prev = nullptr;
        }
    };
    
    Node* head;
    Node* tail;
    int capacity;

   public:
    unordered_map<int, Node*> cache;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNodeToFront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* res = cache[key];
            removeNode(res);
            addNodeToFront(res);

            return res->val;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* updateNode = cache[key];
            updateNode->val = value;
            removeNode(updateNode);
            addNodeToFront(updateNode);
        } else {
            Node* newNode = new Node(key, value);

            cache[key] = newNode;
            addNodeToFront(newNode);
        }
        
        

        if (capacity < cache.size()) {
            Node* lru = tail->prev;

            removeNode(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
