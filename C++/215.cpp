class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(unsigned(time(NULL)));
        int low = 0;
        int n = static_cast<int>(nums.size());
        int high = n - 1;
        int ans = quick_sort(nums, low, high, n - k);
        return ans;

    }

    int quick_sort(vector<int>& nums, int low, int high, int kk) {
        int ans = nums[low];
        if (low < high) {
            int pivot = partition(nums, low, high);
            if (pivot == kk) {
                return nums[pivot];
            }
            if (pivot > kk) {
                ans = quick_sort(nums, low, pivot-1, kk);
            } else {
                ans = quick_sort(nums, pivot+1, high, kk);
            }
        }

        return ans;
    }

    int partition(vector<int>& nums, int low, int high) {
        int pivot = rand() % (high - low + 1) + low;
        swap(nums[low], nums[pivot]);
        int pivot_key = nums[low];
        
        while (low < high) {
            while (low < high) {
                if (nums[high] >=pivot_key) {
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
};