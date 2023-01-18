class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        int n = static_cast<int>(nums.size());
        quick_sort(nums, 0, n-1);
        return nums;
    }

    int Partition(vector<int>& nums, int low, int high) {
        int i = rand() % (high - low + 1) + low;
        swap(nums[low], nums[i]);
        int pivot_key = nums[low];
        while (low < high) {
            while (low < high) {
                if (nums[high] >= pivot_key) {
                    --high;
                } else {
                    nums[low] = nums[high];
                    nums[high] = pivot_key;
                    break;
                }
            }

            while (low < high) {
                if (nums[low] <= pivot_key) {
                    ++low;
                } else {
                    nums[high] = nums[low];
                    nums[low] = pivot_key;
                    break;
                }
            }
        }
        return low;
    }

    void quick_sort(vector<int>& nums, int low, int high) {
        if (low<high) {

            int pivot = Partition(nums, low, high);
            quick_sort(nums, low, pivot-1);
            quick_sort(nums, pivot+1, high);
        }
    }
};