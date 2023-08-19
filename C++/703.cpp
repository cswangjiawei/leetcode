class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int> > que;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums) {
            add(num);
        }
    }
    
    int add(int val) {
        que.push(val);
        if (que.size() > k) {
            que.pop();
        }
        return que.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */