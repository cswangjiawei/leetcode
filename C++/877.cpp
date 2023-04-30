class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));

        for(int i=n-1; i>=0; --i) {
            for (int j=i; j<=n-1; ++j) {
                if (i == j) {
                    dp[i][j] = piles[i];
                } else {
                    dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1]>0;
        
    }
};