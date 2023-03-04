class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int> > queue;
        int n = static_cast<int>(nums.size());

        for (int i=0; i<k; ++i) {
            queue.push(make_pair(nums[i], i));
        }
        ans.emplace_back(queue.top().first);

        for (int j=k; j<n; ++j) {
            while (!queue.empty() && queue.top().second <= j - k) {
                queue.pop();
            }

            queue.push(make_pair(nums[j], j));
            ans.emplace_back(queue.top().first);
        }

        return ans;
    }
};