class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> hash_map;
        stack<int> stk;

        for(int i=0; i<nums2.size(); ++i) {
            if (stk.empty()) {
                stk.push(nums2[i]);
            }

            while(!stk.empty() && stk.top() < nums2[i]) {
                hash_map.insert({stk.top(), nums2[i]});
                stk.pop();
            }
            stk.push(nums2[i]);
        }

        for(int j=0; j<nums1.size(); ++j) {
            if(hash_map.find(nums1[j]) != hash_map.end()) {
                ans.emplace_back(hash_map[nums1[j]]);
            } else {
                ans.emplace_back(-1);
            }
        }

        return ans;
    }
};