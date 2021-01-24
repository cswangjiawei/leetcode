class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max_water = 0;
        int temp_water = 0;
        while (i < j)
        {
            if (height[i] <= height[j])
            {
                temp_water = (j - i) * height[i];
                ++i;
            }
            else
            {
                temp_water = (j - i) * height[j];
                --j;
            }
            if (temp_water > max_water)
            {
                max_water = temp_water;
            }
        }
        return max_water;

    }
};