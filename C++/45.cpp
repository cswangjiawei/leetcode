class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int n = static_cast<int>(nums.size());
        int max_pos = 0;
        int end = 0;

        for (int i=0; i<n-1; ++i) {
            max_pos = max(max_pos, i+nums[i]);
            if (i==end) {
                end = max_pos;
                ++ans;
            } 
        }

        return ans;
    }
};