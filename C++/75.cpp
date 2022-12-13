class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr = 0;
        int cur = 0;
        while(cur < nums.size()) {
            if (nums[cur] == 0) {
                swap(nums[cur], nums[ptr]);
                ++ptr;
            }
            ++cur;
        }

        cur = ptr;
        while(cur < nums.size()) {
            if (nums[cur] == 1) {
                swap(nums[cur], nums[ptr]);
                ++ptr;
            }
            ++cur;
        }
    }
};