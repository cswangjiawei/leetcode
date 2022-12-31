class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> num_count;
        for(int i=0; i < nums.size(); ++i) {
            if(num_count.find(nums[i]) == num_count.end()) {
                num_count[nums[i]] = 0;
            }
            num_count[nums[i]] += 1;
            if (num_count[nums[i]] > nums.size() / 2) {
                return nums[i];
            }
        }
        return 0;

    }
};