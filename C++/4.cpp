class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num;
        int len_nums1 = nums1.size();
        int len_nums2 = nums2.size();
        int i = 0;
        int j = 0;

        int sum_len = len_nums1 + len_nums2;
        bool flag = false;
        if (sum_len % 2 == 1)
        {
            flag = true;
        }
        int mid_index = sum_len / 2;
        while (i < len_nums1 && j < len_nums2)
        {
            if (nums1[i] < nums2[j])
            {
                num.emplace_back(nums1[i]);
                ++i;
            }
            else
            {
                num.emplace_back(nums2[j]);
                ++j;
            }
        }
        if (num.size() > mid_index)
        {
            if (flag)
            {
                return num[mid_index];
            }
            else
            {
                return (static_cast<double>(num[mid_index-1])+static_cast<double>(num[mid_index]))/2;
            }
        }
        else
        {
            while (i < len_nums1)
            {
                num.emplace_back(nums1[i]);
                ++i;
            }
            while (j < len_nums2)
            {
                num.emplace_back(nums2[j]);
                ++j;
            }
            if (flag)
            {
                return num[mid_index];
            }
            else
            {
                return (static_cast<double>(num[mid_index-1])+static_cast<double>(num[mid_index]))/2;
            }
        }
        
    }
};