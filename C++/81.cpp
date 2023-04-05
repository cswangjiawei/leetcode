class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        int left = 0;
        int right = n - 1;
        
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) {
                return true;
            }

            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                ++left;
                --right;
                continue;
            }

            if (nums[left] <= nums[mid]) {
                if (nums[mid] > target && nums[left] <= target) {
                    right = mid -1;
                } else {
                    left = mid + 1;
                }

                continue;
            }

            if (nums[mid] <= nums[right]) {
                if (nums[mid] < target && nums[right] >= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } 
        }

        return false;
    }
};