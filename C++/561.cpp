class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=0; i+1<nums.size();) {
            ans += min(nums[i], nums[i+1]);
            i += 2;
        }

        return ans;
    }
};