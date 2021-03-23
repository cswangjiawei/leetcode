class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1)
        {
            return nums.size();
        }
        int start = 0;
        int end = 1;
        int max_len = 1;
        int temp = 0;
        while (end < nums.size())
        {
            if (nums[end] <= nums[end - 1])
            {
                temp = end - start;
                if (temp > max_len)
                {
                    max_len = temp;
                }
                start = end;
            }
            ++end;
        }

        temp = end - start;
        if (temp > max_len)
        {
            max_len = temp;
        }
        return max_len;
    }
};