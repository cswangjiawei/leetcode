class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int s_size = s.size();
        vector<vector<int> > dp(s_size, vector<int>(s_size,1));
        for (int i=0; i<s_size;++i) {
            dp[i][i] = 1;
        }
        for(int i=0; i<s_size-1; ++i) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = 2;
            }
        }

        int distance = 2;
        while (distance<s_size) {
            for (int i=0; i+distance<s_size; ++i) {
                int j = i + distance;
                if (s[i]==s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
            ++distance;
        }

        return dp[0][s_size-1];
    }
};