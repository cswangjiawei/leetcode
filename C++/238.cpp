class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> ans(n, 0);

        vector<int> left_proudct(n, 1);
        for(int i=1; i<n; ++i) {
            left_proudct[i] = left_proudct[i-1] * nums[i-1];
        }

        vector<int> right_product(n, 1);
        right_product[n-1] = 1;
        for(int i=n-2; i>=0; --i) {
            right_product[i] = right_product[i+1] *nums[i+1];
        }

        for(int i=0; i<n; ++i) {
            ans[i] = left_proudct[i] * right_product[i];
        }

        return ans;
    }
};