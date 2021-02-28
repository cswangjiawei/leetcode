class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        for (int i = 0; i < nums.size(); ++i)
        {
            if ( i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }
            if (nums[i] > 0)
            {
                break;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < nums.size() - 1 && k > j)
            {
                if ( j > i + 1 && nums[j] == nums[j-1])
                {
                    ++j;
                    continue;
                }
                if (nums[j] + nums[k] == -nums[i])
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    result.emplace_back(temp);
                    ++j;
                    --k;
                }
                else if (nums[j] + nums[k] > -nums[i])
                {
                    --k;
                }
                else
                {
                    ++j;
                }
            }
        }
        return result;
    }
};