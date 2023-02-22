class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map1;
        map1[0] = 1;

        int ans = 0;

        int pre = 0;
        for (int& num: nums) {
            pre += num;
            if (map1.find(pre-k) != map1.end()) {
                ans += map1[pre-k];
            }
            map1[pre]++;
        }


        return ans;
    }
};