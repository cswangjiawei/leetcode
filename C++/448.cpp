class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] != i + 1) {
                if (nums[i] != nums[nums[i]-1]) {
                    swap(nums[i], nums[nums[i]-1]);
                    --i;
                }
            }
        }

        for(int i=0; i<nums.size(); ++i) {
            if (nums[i] != i+1) {
                ans.emplace_back(i+1);
            }
        }

        return ans;
    }
};