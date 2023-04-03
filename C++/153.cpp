class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int low = 0;
        int high = n - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};