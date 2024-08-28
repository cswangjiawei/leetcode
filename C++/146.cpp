class DLinkNode {
    public:
        int key;
        int val;
        DLinkNode* prev;
        DLinkNode* next;
    
        DLinkNode(): val(0), prev(nullptr), next(nullptr) {};
        DLinkNode(int key, int val): key(key), val(val), prev(nullptr), next(nullptr) {};
        DLinkNode(int key, int val, DLinkNode* prev, DLinkNode* next): key(key), val(val), prev(prev), next(next) {};
};

class LRUCache {
    std::unordered_map<int, DLinkNode*> mp;
    int capacity;
    int size;
    DLinkNode* dummy_head;
    DLinkNode* dummy_tail;
public:
    LRUCache(int capacity): capacity(capacity), size(0) {
        dummy_head = new DLinkNode();
        dummy_tail = new DLinkNode();
        dummy_head->next = dummy_tail;
        dummy_tail->prev = dummy_head;

    }

    void remove_node(DLinkNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = nullptr;
        node->next = nullptr;
    }

    void add_to_head(DLinkNode* node) {
        dummy_head->next->prev = node;
        node->next = dummy_head->next;
        dummy_head->next = node;
        node->prev = dummy_head;
    }
    
    int get(int key) {
        if (mp.count(key)) {
            remove_node(mp[key]);
            add_to_head(mp[key]);
            return mp[key]->val;
        } else {
            return -1;
        } 
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            mp[key]->val = value;
            remove_node(mp[key]);
            add_to_head(mp[key]);
        } else {
            if (size == capacity) {
                auto node = dummy_tail->prev;
                remove_node(node);
                mp.erase(node->key);
                delete node;
                --size;
            }
            DLinkNode* node = new DLinkNode(key, value);
            mp[key] = node;
            add_to_head(node);
            ++size;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */