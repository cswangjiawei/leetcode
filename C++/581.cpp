class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (is_sorted(nums.begin(), nums.end()) ) {
            return 0;
        }

        int n = static_cast<int>(nums.size());

        vector<int> sorted_nums(nums);
        sort(sorted_nums.begin(), sorted_nums.end());
        int left = 0;
        int right = n - 1;

        while(left < n) {
            if (nums[left] != sorted_nums[left]) {
                break;
            }
            ++left;
        }

        while(right >= 0) {
            if (nums[right] != sorted_nums[right]) {
                break;
            }
            --right;
        }

        return (right - left + 1) > 0 ? (right - left + 1) : 0;
    }
};