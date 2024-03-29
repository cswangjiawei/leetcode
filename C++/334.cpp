class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_min(n, 0);
        vector<int> right_max(n, 0);
        left_min[0] = nums[0];
        right_max[n-1] = nums[n-1];

        for (int i=1; i<n; ++i) {
            left_min[i] = min(left_min[i-1], nums[i]);
        }

        for (int i=n-2; i>=0; --i) {
            right_max[i] = max(right_max[i+1], nums[i]);
        }

        for (int i=1; i<n-1; ++i) {
            if (nums[i] > left_min[i] && nums[i] < right_max[i]) {
                return true;
            }
        }

        return false;
    }
};


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for(int num: nums) {
            if (num > second) {
                return true;
            }
            if (num > first) {
                second = num;
                continue;
            }
            first = num;

        }

        return false;
    }
};