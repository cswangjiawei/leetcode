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


     class Node {
        public:
            int key;
            int value;
            int cnt;
            int time;
        public:
            Node(int key, int value, int cnt, int time): key(key), value(value), cnt(cnt), time(time) {}
            Node(int key, int value): key(key), value(value), cnt(1), time(0) {}
            Node(): key(0), value(0), cnt(1), time(0) {}
        
            bool operator < (const Node& rhs) const {
                return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
            }
        }; 
        
        class LFUCache {
            std::unordered_map<int, Node> mp;
            std::set<Node> cache;
            int capacity;
            int size;
            int time;
        public:
            LFUCache(int capacity): capacity(capacity), size(0), time(0) {
                mp.clear();
                cache.clear();
            }
            
            int get(int key) {
                if (mp.count(key)) {
                    Node node = mp[key];
                    cache.erase(node);
        
                    ++time;
                    node.time = time;
                    ++node.cnt;
                    cache.insert(node);
                    mp[key] = node;
                    return node.value;
                } else {
                    return -1;
                }
            }
            
            void put(int key, int value) {
                if (mp.count(key)) {
                    Node node = mp[key];
                    
                    cache.erase(node);
                    node.value = value;
                    ++time;
                    node.time = time;
                    ++node.cnt;
                    cache.insert(node);
                    mp[key] = node;
                } else {
                    if (size == capacity) {
                        auto it = cache.begin();
                        mp.erase(it->key);
                        cache.erase(it);
                        --size;
                    }
                    ++time;
                    Node node(key, value, 1, time);
                    cache.insert(node);
                    mp.insert({key, node});
                    ++size;
                }
            }
        };
        
        /**
         * Your LFUCache object will be instantiated and called as such:
         * LFUCache* obj = new LFUCache(capacity);
         * int param_1 = obj->get(key);
         * obj->put(key,value);
         */