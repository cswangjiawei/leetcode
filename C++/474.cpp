class Solution {
public:
    vector<int> get_zero_one_cnt(string& str) {
        vector<int> cnt(2);
        for (char ch: str) {
            ++cnt[ch - '0'];
        }
        return cnt;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int strs_size = strs.size();
        vector<vector<vector<int> > > dp(strs_size+1, vector<vector<int> >(m+1,vector<int>(n+1)));
        for(int i=1; i<=strs_size; ++i) {
            vector<int> zero_one_cnt = get_zero_one_cnt(strs[i-1]);
            int zero_cnt = zero_one_cnt[0];
            int one_cnt = zero_one_cnt[1];
            for (int j=0; j<=m; ++j) {
                for (int k=0; k<=n; ++k) {
                    if (j<zero_cnt || k<one_cnt) {
                        dp[i][j][k] = dp[i-1][j][k];
                    } else {
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-zero_cnt][k-one_cnt]+1);
                    }
                }
            }
        }
        return dp[strs_size][m][n];
    }
};