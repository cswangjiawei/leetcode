class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = static_cast<int>(nums1.size());
        int n2 = static_cast<int>(nums2.size());

        vector<vector<int> > dp(n1+1, vector<int>(n2+1, 0));

        for (int i=1; i<=n1; ++i) {
            for (int j=1; j<=n2; ++j) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        return dp[n1][n2];
    }
};