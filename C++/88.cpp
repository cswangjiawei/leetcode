class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = m + n - 1;
        while (m && n) {
            if (nums1[m-1] > nums2[n-1]) {
                nums1[j] = nums1[m-1];
                --m;
            } else {
                nums1[j] = nums2[n-1];
                --n;
            }
            --j;
        }

        if (m == 0) {
            while (n) {
                nums1[j] = nums2[n-1];
                --n;
                --j;
            }
        }
    }
};