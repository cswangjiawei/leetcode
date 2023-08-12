class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int> > que;
        for (int stone: stones) {
            que.push(stone);
        }

        while(que.size() >= 2) {
            int y = que.top();
            que.pop();
            int x = que.top();
            que.pop();
            if (x!=y) {
                que.push(y-x);
            }
        }
        if (!que.empty()) {
            return que.top();
        } else {
            return 0;
        }
    }
};