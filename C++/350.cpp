class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int n1 = static_cast<int>(nums1.size());
        int n2 = static_cast<int>(nums2.size());

        int index1 = 0;
        int index2 = 0;

        while (index1 < n1 && index2 < n2) {
            if (nums1[index1] == nums2[index2]) {
                ans.emplace_back(nums1[index1]);
                ++index1;
                ++index2;
                continue;
            }
            if (nums1[index1] < nums2[index2]) {
                ++index1;
            } else {
                ++index2;
            }
        }

        return ans;
    }
};