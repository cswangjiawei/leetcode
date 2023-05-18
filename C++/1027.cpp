class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        auto [minval, maxval] = minmax_element(nums.begin(), nums.end());
        int diff = *maxval - *minval;

        int ans = 1;
        for (int d=-diff; d<=diff; ++d) {
            vector<int> f(*maxval + 1, -1);
            for(int num: nums) {
                if (int prev = num - d; prev >= *minval && prev <= *maxval && f[prev] != -1) {
                    f[num] = max(f[num], f[prev] + 1);
                    ans = max(ans, f[num]);
                }
                f[num] = max(f[num], 1);
            }
        }

        return ans;
    }
};