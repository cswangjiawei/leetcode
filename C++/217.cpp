class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set1;
        for(int i=0; i<nums.size(); ++i) {
            if (set1.find(nums[i])!=set1.end()) {
                return true;
            }
            set1.insert(nums[i]);
        }

        return false;
    }
};