class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> factors = {2, 3, 5};
        priority_queue<long long, vector<long long>, greater<long long> > que;
        que.push(1);
        long long  ugly = 1;
        unordered_set<long long> seen;
        seen.insert(1);
        for (int i=0; i<n; ++i) {
            ugly = que.top();
            que.pop();
            for (int factor: factors) {
                long long tmp = ugly * factor;
                if (seen.count(tmp) == 0) {
                    que.push(tmp);
                    seen.insert(tmp);
                }            
            }
        }
        return ugly;
    }
};