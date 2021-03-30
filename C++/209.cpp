class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int nums_size = static_cast<int>(nums.size());
        int sum = 0;
        int min_len = nums_size + 1;
        int cur_len = 0;
        while (end < nums_size)
        {
            sum += nums[end];
            while (sum >= target && start <= end)
            {
                cur_len = end - start + 1;
                if (cur_len < min_len)
                {
                    min_len = cur_len;
                }
                sum -= nums[start];
                ++start;
            }
            ++end;
        }
        if (min_len > nums_size)
        {
            min_len = 0;
        }
        return min_len;
    }
};