class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = static_cast<int>(digits.size());
        int i = n-1;
        bool flag = false;
        while(i>=0) {
            int tmp = (digits[i] + 1)%10;
            digits[i] = tmp;
            if (tmp) {
                break;
            }
            --i;
            if (i==-1 && tmp==0) {
                flag = true;
            }
        }

        if (flag) {
            vector<int> ans;
            ans.emplace_back(1);
            for (int& e: digits) {
                ans.emplace_back(e);
            }
            return ans;
        }
        return digits;
    }
};