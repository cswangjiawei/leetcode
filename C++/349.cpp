class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        int n = static_cast<int>(nums1.size());
        for (int i=0; i<n; ++i) {
            if (i>0 && nums1[i] == nums1[i-1]) {
                continue;
            }
            if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end()) {
                ans.emplace_back(nums1[i]);
            }
        }

        return ans;
    }
};