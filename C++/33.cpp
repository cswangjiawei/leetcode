#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size() - 1;
        int left = 0;
        int mid = -1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[left] <= nums[mid])
            {
                if (target >= nums[left] && target <= nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
                continue;
            }
            if (nums[mid] <= nums[right])
            {
                if (target >= nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    Solution solu;
    int result = solu.search(nums, target);
    cout<<result<<endl;
    return 0;
}