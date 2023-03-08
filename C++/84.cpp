class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = static_cast<int>(heights.size());
        stack<int> stk;
        vector<int> left(n);
        vector<int> right(n);

        int ans = 0;

        for (int i=0; i<n; ++i) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        stack<int> stk2;
        for (int i=n-1; i>=0; --i) {
            while (!stk2.empty() && heights[stk2.top()] >= heights[i]) {
                stk2.pop();
            }
            right[i] = stk2.empty() ? n : stk2.top();
            stk2.push(i);
        }

        for (int i=0; i<n; ++i) {
            int cur_area = (right[i] - left[i] - 1) * heights[i];
            ans = max(ans, cur_area);
        }

        return ans;
    }
};