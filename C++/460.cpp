class DLinkNode {
    public:
        int key;
        int value;
        int cnt;
    
        DLinkNode* prev;
        DLinkNode* next;
    
        DLinkNode(int key, int value, int cnt, DLinkNode* prev, DLinkNode* next): key(key), value(value), cnt(cnt), prev(prev), next(next) {}
        DLinkNode(int key, int value, int cnt): key(key), value(value), cnt(cnt), prev(nullptr), next(nullptr) {}
    };
    
    class LFUCache {
        unordered_map<int, DLinkNode*> mp;
        int capacity;
        DLinkNode* head;
        DLinkNode* tail;
    
    public:
        LFUCache(int capacity): capacity(capacity) {
            head = new DLinkNode(0, 0, 1);
            tail = new DLinkNode(0, 0, 1);
            head->next = tail;
            tail->prev = head;
        }
    
        void remove_node(DLinkNode* node) {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            node->next = nullptr;
            node->prev = nullptr;
        }
        
        void move_node(DLinkNode* node) {
            DLinkNode* cur = node->prev;
            while (cur != head && cur->cnt <= node->cnt) {
                cur = cur->prev;
            }
            remove_node(node);
            node->next = cur->next;
            cur->next->prev = node;
            node->prev = cur;
            cur->next = node;
        }
    
        void insert_node(DLinkNode* node) {
            DLinkNode* prev_node = head;
            while (prev_node->next != tail && prev_node->next->cnt > node->cnt) {
                prev_node = prev_node->next;
            }
            node->next = prev_node->next;
            prev_node->next->prev = node;
            node->prev = prev_node;
            prev_node->next = node;
        }
    
        int get(int key) {
            if (mp.count(key)) {
                DLinkNode* node = mp[key];
                node->cnt += 1;
                move_node(node);
                return node->value;
            } else {
                return -1;
            }
        }
        
        void put(int key, int value) {
            if (mp.count(key)) {
                DLinkNode* node = mp[key];
                node->value = value;
                node->cnt += 1;
                move_node(node);
            } else {
                DLinkNode* node = new DLinkNode(key, value, 1);
                if (mp.size() < capacity) {
                    insert_node(node);
                    mp.insert({key, node});
                } else {
                    mp.erase(tail->prev->key);
                    remove_node(tail->prev);
                    insert_node(node);
                    mp.insert({key, node});
                }
            }
        }
    };
    
    /**
     * Your LFUCache object will be instantiated and called as such:
     * LFUCache* obj = new LFUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */