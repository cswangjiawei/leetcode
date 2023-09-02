class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto compare = [=](int a, int b) {
            if (abs(a-x) != abs(b-x)) {
                return abs(a-x) > abs(b-x);
            } else {
                return a > b;
            }
        };
        priority_queue<int, vector<int>, decltype(compare)> que(compare);
        for(int x: arr) {
            que.push(x);
        }


        vector<int> ans;
        while(k>0) {
            int tmp = que.top();
            ans.emplace_back(tmp);
            que.pop();
            --k;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;
        while (k) {
            if (left < 0) {
                ++right;
            } else if (right >= arr.size()) {
                --left;
            } else if (abs(arr[right]-x) < abs(arr[left] - x)) {
                ++right;
            } else {
                --left;
            }
            --k;
        }
        return {arr.begin()+left+1, arr.begin()+right};

        
    }
};