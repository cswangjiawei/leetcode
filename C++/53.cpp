class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int max_pre = 0;
        for (const auto &num: nums)
        {
            max_pre = max(max_pre+num, num);
            if (max_pre > result)
            {
                result = max_pre;
            }
        }
        return result;
    }
};