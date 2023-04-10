class MyQueue {
private:
    stack<int> stk1;
    stack<int> stk2;
public:
    MyQueue() {

    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        if (!stk2.empty()) {
            auto ans = stk2.top();
            stk2.pop();
           return ans;
        }
        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        auto ans = stk2.top();
        stk2.pop();
        return ans;
    
    }
    
    int peek() {
        if (!stk2.empty()) {
          return  stk2.top();
        }
        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        return stk2.top();
    }
    
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */