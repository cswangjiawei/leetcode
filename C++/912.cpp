#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = static_cast<int>(nums.size()) - 1;
        quick_sort(nums, 0, n);
        return nums;
    }

    int partition(vector<int> &nums, int low, int high)
    {
        int pivotkey = nums[low];
        while (low < high)
        {
            while (low < high)
            {
                if (nums[high] < pivotkey)
                {
                    nums[low] = nums[high];
                    nums[high] = pivotkey;
                    break;
                }
                else
                {
                    --high;
                }
            }
            while (low < high)
            {
                if (nums[low] > pivotkey)
                {
                    nums[high] = nums[low];
                    nums[low] = pivotkey;
                    break;
                }
                else
                {
                    ++low;
                }
            }
        }
        nums[low] = pivotkey;
        return low;
    }

    void quick_sort(vector<int> &nums, int low, int high)
    {
        if (low < high)
        {
            int pivot = partition(nums, low, high);
            quick_sort(nums, low, pivot-1);
            quick_sort(nums, pivot+1, high);
        }
    }
};

int main()
{
    Solution solu;
    vector<int> nums = {5,2,3,1};
    solu.sortArray(nums);
    return 0;
}
