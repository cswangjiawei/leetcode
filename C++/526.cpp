class Solution {
    int ans;
public:
    int countArrangement(int n) {
        vector<bool> visited(n+1, false);
        back_ward(1, visited, n);
        return ans;
    }

    void back_ward(int start, vector<bool>& visited, int n) {
        if (start == n+1) {
            ++ans;
            return;
        }
        for (int i=1; i<n+1; ++i) {
            if (!visited[i]) {
                if (start%i==0 || i%start==0) {
                    visited[i] = true;
                    back_ward(start+1, visited, n);
                    visited[i] = false;
                }
            }
        }
    }
};