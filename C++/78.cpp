class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> temp;
        back_track(nums, temp, 0, result);
        return result;
    }

    void back_track(vector<int>& nums, vector<int>& temp, int index, vector<vector<int> >& result)
    {
        if (index == nums.size())
        {
            result.emplace_back(temp);
            return;
        }
        temp.emplace_back(nums[index]);
        back_track(nums, temp, index+1, result);
        temp.pop_back();
        back_track(nums, temp, index+1, result);
    }
};