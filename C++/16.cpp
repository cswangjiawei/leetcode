class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size()<3)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int temp = 0;
        int three_sum = nums[0] + nums[1] + nums[nums.size()-1];

        for (int i=0; i<nums.size(); ++i)
        {
            int k = i + 1;
            int j = nums.size() - 1;
            while (k > 0 && k < j)
            {
                temp = nums[i] + nums[j] + nums[k];
                if (abs(target-temp) < abs(target - three_sum))
                {
                    three_sum = temp;
                }
                if (temp > target)
                {
                    --j;
                }
                else
                {
                    ++k;
                }
            }
        }
        return three_sum;
    }
};