class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index1 = -1;
        for (int i=nums.size()-1; i > 0; --i)
        {
            if (nums[i] > nums[i-1])
            {
                index1 = i - 1;
                break;
            }
        }
        if (index1 == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i=nums.size()-1; i > index1; --i)
        {
            if (nums[i] > nums[index1])
            {
                swap(nums[i], nums[index1]);
                reverse(nums.begin()+index1+1, nums.end());
                break;
            }
        }
    }
};