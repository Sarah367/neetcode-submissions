class LRUCache {
public:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        Node* previous = node->prev;
        Node* after = node->next;

        previous->next = after;
        after->prev = previous;
    }
    
    void insert(Node* node) {
        Node* temp = head->next;
        
        head->next = node;
        node->next = temp;
        node->prev = head;
        temp->prev = node;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->val = value;
            remove(cache[key]);
            insert(cache[key]);
        } else {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insert(cache[key]);
        }

        if (capacity < cache.size()) {
            Node* removeNode = tail->prev;
            remove(removeNode);
            cache.erase(removeNode->key);
            delete removeNode;
        }
    }
};
