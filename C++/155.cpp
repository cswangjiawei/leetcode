class MinStack {
public:
    stack<int> stk;
    stack<int> auxilary_stk;

    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        if (auxilary_stk.empty() || auxilary_stk.top() >= val) {
            auxilary_stk.push(val);
        }
    }
    
    void pop() {
        if (!auxilary_stk.empty() && auxilary_stk.top() == stk.top()) {
            auxilary_stk.pop();
        }
        stk.pop();

    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return auxilary_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */