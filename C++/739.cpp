class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> stk;

        for(int i=0; i<temperatures.size(); ++i) {
            if(stk.empty()) {
                stk.push(i);
            }

            while(!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                int top_i = stk.top();
                stk.pop();
                ans[top_i] = i - top_i;
            }
            stk.push(i);
        }

        return ans;
        
    }
};