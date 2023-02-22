class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        int n = static_cast<int>(nums.size());
        if (n==1) {
            return nums[0];
        }

        vector<int> dy_vec(n, 0);
        dy_vec[0] = nums[0];
        dy_vec[1] = max(dy_vec[0], nums[1]);
        if (n==2) {
            return dy_vec[1];
        }

        for (int i=2; i<n-1; ++i) {
            dy_vec[i] = max(dy_vec[i-1], dy_vec[i-2] + nums[i]);
        }

        vector<int> dy_vec2(n, 0);
        dy_vec2[1] = nums[1];
        dy_vec2[2] = max(dy_vec2[1], nums[2]);
        for(int i=3; i<n; ++i) {
            dy_vec2[i] = max(dy_vec2[i-1], dy_vec2[i-2] + nums[i]);
        }

        ans = max(dy_vec[n-2], dy_vec2[n-1]);
        return ans;
    }
};