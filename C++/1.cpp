class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_map;
        for (int i=0; i<nums.size(); ++i) 
        {
            auto remind = target - nums[i];
            auto iter = hash_map.find(remind);
            if (iter != hash_map.end())
            {
                return {iter->second, i};
            }
            else
            {
                hash_map.emplace(make_pair(nums[i], i));
            }
        }
        return {};
    }
};