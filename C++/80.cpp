class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int i = 0;
        int j = 1;

        int count = 1;
        while (j < n) {
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j];
                count = 1;
            } else if (nums[j] == nums[i] && count < 2) {
                nums[++i] = nums[j];
                ++count;
            }
            ++j;
        }

        return ++i; 
    }
};