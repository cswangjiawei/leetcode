class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> num_set;
        for(int num: nums) {
            num_set.insert(num);
        }


        for(int i=0; i<nums.size(); ++i) {
            if(num_set.count(nums[i]-1) != 0) {
                continue;
            }
            int tmp = 0;
            int cur_num = nums[i];
            while(num_set.count(cur_num)) {
                ++cur_num;
                ++tmp;
            }
            if (tmp > ans) {
                ans = tmp;
            }        
        }  
        return ans;     
    }
};
