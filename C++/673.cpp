class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        int maxlen = 1;
        int ans = 0;

        for (int i=0; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if (dp[i] > maxlen) {
                ans = cnt[i];
                maxlen = dp[i];
            } else if (dp[i] == maxlen) {
                ans += cnt[i];
            }
        }

        return ans;
    }
};