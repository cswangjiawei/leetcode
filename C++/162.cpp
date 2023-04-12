class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int left = 0;
        int right = n - 1;

        auto get = [&](int idx) ->pair<int, int> {
            if (idx<0 || idx==n) {
                return {0, 0};
            }
            return {1, nums[idx]};
        };

        while (left <= right) {
            int mid = (left + right) / 2;
            if (get(mid) > get(mid-1) && get(mid) > get(mid+1)) {
                return mid;
            }
            if (get(mid) < get(mid+1)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};