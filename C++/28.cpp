class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;
        int ptr = 0;
        
        int n = static_cast<int>(haystack.size());
        int m = static_cast<int>(needle.size());

        for (int i=0; i<n; ++i) {
            
            if (haystack[i] == needle[ptr]) {
                ans = i;
                int j = i+1;
                ++ptr;
                while (j<n && ptr < m && haystack[j] == needle[ptr]) {
                    ++j;
                    ++ptr;
                }
                i = ans;
            }


            if (ptr == m) {
                break;
            } else {
                ans = -1;
                ptr = 0;
            }

        }

        return ans;
    }
};