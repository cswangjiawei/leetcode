class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i=nums.size()-1; i>=2; --i) {
            for (int j=0; j<nums.size()-2; ++j) {
                int left = j+1;
                int right = i-1;
                int k = i;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (nums[j] + nums[mid] > nums[i]) {
                        right = mid - 1;
                        k = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                ans += (i - k);
            }
        }
        return ans;
    }
};