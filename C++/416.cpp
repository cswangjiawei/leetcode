class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int summ = accumulate(nums.begin(), nums.end(), 0);
        if (summ%2) {
            return false;
        }

        int max_num = *max_element(nums.begin(), nums.end());
        int target = summ / 2;
        if (max_num > target) {
            return false;
        }
        if (max_num == target) {
            return true;
        }

        int n = static_cast<int>(nums.size());
        vector<vector<bool> > dy_vec(n, vector<bool>(target+1, false));

        dy_vec[0][nums[0]] = true;
        dy_vec[0][0] = true;
        for (int i=1; i<n; ++i) {
            dy_vec[i][0] = true;
            for (int j=1; j<=target; ++j) {
                if (j >= nums[i])
                    dy_vec[i][j] = dy_vec[i-1][j] | dy_vec[i-1][j-nums[i]];
                else
                    dy_vec[i][j] = dy_vec[i-1][j];
            }
        }

        return dy_vec[n-1][target];
    }
};