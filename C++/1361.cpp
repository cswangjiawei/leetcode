class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);
        for (auto &e: leftChild) {
            if  (e!= -1)
                indegree[e]++;
        }
        for (auto &e: rightChild) {
            if (e!=-1)
                indegree[e]++;
        }

        int root = -1;
        for (int i=0; i<n; ++i) {
            if (indegree[i]==0) {
                root = i;
            }
        }
        if (root == -1) {
            return false;
        }

        unordered_map<int, int> seen;
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (seen.count(cur)) {
                return false;
            }
            
            seen.insert({cur, 1});
            auto left_e = leftChild[cur];
            if (left_e != -1) {
                q.push(left_e);
            }
            auto right_e = rightChild[cur];
            if (right_e != -1) {
                q.push(right_e);
            }
        }

        return seen.size() == n;

    }
};