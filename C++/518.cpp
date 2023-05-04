class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int> > dp(n, vector<int>(amount+1, 0));
        for (int i=0; i<=amount; ++i) {
            if (i%coins[0]==0) {
                dp[0][i] = 1;
            } else {
                dp[0][i] = 0;
            }
        }

        for (int i=1; i<n; ++i) {
            dp[i][0] = 1;
        }

        for (int i=1; i<n; ++i) {
            for (int j=0; j<=amount; ++j) {
                if (j >= coins[i]) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n-1][amount];
    }
};