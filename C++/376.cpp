class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 1;
        int direction = 0;
        for (int i=1; i<nums.size(); ++i) {
            if (direction==0) {
                if (nums[i] > nums[i-1]) {
                    ++ans;
                    direction = 1;
                    continue;
                }
                if (nums[i] < nums[i-1]) {
                    ++ans;
                    direction = -1;
                    continue;
                }
            }

            if (direction==1 && nums[i] < nums[i-1]) {
                ++ans;
                direction = -1;
                continue;
            }

            if (direction==-1 && nums[i] > nums[i-1]) {
                ++ans;
                direction = 1;
                continue;
            }
        }
        return ans;
    }
};