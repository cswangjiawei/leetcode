class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto compare = [=](int a, int b) {
            if (abs(a-x) != abs(b-x)) {
                return abs(a-x) > abs(b-x);
            } else {
                return a > b;
            }
        };
        priority_queue<int, vector<int>, decltype(compare)> que(compare);
        for(int x: arr) {
            que.push(x);
        }


        vector<int> ans;
        while(k>0) {
            int tmp = que.top();
            ans.emplace_back(tmp);
            que.pop();
            --k;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};