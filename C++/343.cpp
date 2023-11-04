class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 1;
        int ans = integerBreak_dp(n, dp);
        return ans;
        
    }

    int integerBreak_dp(int n, vector<int>& dp) {

        int ans = 1;
        for(int i=1; i<n; ++i) {
            int tmp;
            if (dp[n-i]) {
                tmp = max(i*dp[n-i], i*(n-i));
            } else {
                tmp = max(i*integerBreak_dp(n-i, dp), i*(n-i));
            }
            ans = max(ans, tmp);
        }
        dp[n] = ans;
        return ans;
    }
};