class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binary_search_left(nums, target);
        int right = binary_search_right(nums, target);
        vector<int> result;
        result.emplace_back(left);
        result.emplace_back(right);
        return result;
    }

    int binary_search_left(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = -1;
        int result = -1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                if (result==-1 || mid < result)
                {
                    result = mid;
                }
            }
            if (nums[mid] >= target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return result;
    }

    int binary_search_right(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = -1;
        int result = -1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                if (result==-1 || mid > result)
                {
                    result = mid;
                }
            }
            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return result;
    }
};