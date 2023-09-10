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


class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;

        int i = 1;
        while(i<n) {
            int tmp = min(min(dp[p2]*2, dp[p3]*3), dp[p5]*5);
            if (tmp == dp[p2]*2) {
                ++p2;
            }
            if (tmp == dp[p3]*3) {
                ++p3;
            }
            if (tmp == dp[p5]*5) {
                ++p5;
            }
            dp[i] = tmp;
            ++i;
        }
        return dp[n-1]; 
    }
};