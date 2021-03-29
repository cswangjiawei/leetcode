class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> num_set;
        int n = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (num_set.size() < k+1)
            {
                if (num_set.find(nums[i]) != num_set.end())
                {
                    return true;
                }
                num_set.insert(nums[i]);
            }
            else
            {
                ++n;
                num_set.erase(nums[n]);
                --i;
            }
        }
        return false;
    }
};