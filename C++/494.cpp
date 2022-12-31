class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int summ = 0;
        int ans = 0;
        target_sum(nums, target, 0, summ, ans);
        return ans;

    }

    void target_sum(vector<int>& nums, int target, int index, int summ, int& ans) {
        if (index == nums.size()) {
            return;
        }
        if (index == nums.size() - 1) {
            if (summ + nums[index] == target) {
                ans += 1;
            }

            if (summ - nums[index] == target) {
                ans += 1;
            }
            return;
        }

        target_sum(nums, target, index+1, summ+nums[index], ans);
        target_sum(nums, target, index+1, summ-nums[index], ans);
    }
};