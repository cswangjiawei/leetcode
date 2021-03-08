class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > result;
        backtrack(result, nums, 0);
        return result;
    }

    void backtrack(vector<vector<int> > &result, vector<int> &nums, int idx)
    {
        if (idx == nums.size())
        {
            result.emplace_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); ++i)
        {
            swap(nums[idx], nums[i]);
            backtrack(result, nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }
};