class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        int n = static_cast<int>(nums.size());
        vector<int> tmp;
        backtrack(nums, ans, tmp, 0, n);
        return ans;

    }

    void backtrack(vector<int>& nums, vector<vector<int> >& ans, vector<int>& tmp, int index, int n) {
        if (index == n) {
            ans.push_back(tmp);
            return;
        }

        tmp.push_back(nums[index]);
        backtrack(nums, ans, tmp, index+1, n);
        tmp.pop_back();

        while(index+1<n && nums[index] == nums[index+1]) {
            ++index;
        }

        backtrack(nums, ans,  tmp, index+1, n);
    }
};