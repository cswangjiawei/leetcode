class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int low = 0;
        int n = static_cast<int>(arr.size());
        vector<int> ans;
        quick_sort(arr, low, n-1, k-1);
        for(int i=0; i<k; ++i) {
            ans.emplace_back(arr[i]);
        }
        return ans;
    }

    void quick_sort(vector<int>& nums, int low, int high, int kk) {
        if (low < high) {
            int pivot = partition(nums, low, high);
            if (pivot == kk) {
                return;
            }
            if (pivot > kk) {
                quick_sort(nums, low, pivot-1, kk);
            } else {
                quick_sort(nums, pivot+1, high, kk);
            }
        }

        return;
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