class Solution {
public:
    bool canJump(vector<int>& nums) {
        int rightmost = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if ( i <= rightmost)
            {
                rightmost = max(i + nums[i], rightmost);
            }
            if (rightmost >= nums.size() - 1)
            {
                return true;
            }
        }
        return false;
    }
};