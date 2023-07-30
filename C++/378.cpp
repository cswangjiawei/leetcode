class Solution {

struct ele {
    ele(int x, int y, int val):x(x), y(y), val(val) {};
    int x;
    int y;
    int val;
};

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        auto compare = [](ele& a, ele& b) {return a.val > b.val;};
        priority_queue<ele, vector<ele>, decltype(compare) > queue(compare);
        int n = matrix.size();
        for (int i=0; i<n; ++i) {
            queue.push(ele(i, 0, matrix[i][0]));
        }

        int ans = 0;
        while(k) {
            auto tmp = queue.top();
            if (tmp.y<n-1) {
                queue.push(ele(tmp.x, tmp.y+1, matrix[tmp.x][tmp.y+1]));
            }
            queue.pop();
            ans = tmp.val;
            --k;
        }
        return ans;
    }
};