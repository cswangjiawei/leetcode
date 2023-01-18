class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = INT_MIN;
        int pre_max_val = 1;
        int pre_min_val = 1;

        for(int i=0; i<n; ++i) {
            ans = max(ans, max(nums[i], max(pre_max_val*nums[i], pre_min_val*nums[i])));

            int old_pre_max_val = pre_max_val;
            pre_max_val = max(max(pre_min_val*nums[i],pre_max_val*nums[i]), nums[i]);
            pre_min_val = min(min(pre_min_val*nums[i],old_pre_max_val*nums[i]), nums[i]);
        }

        return ans;
    }
};