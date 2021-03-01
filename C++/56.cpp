#include <vector>
#include <algorithm>
// #include <numeric>
using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }
            else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};

int main()
{
    vector<int> vec1 = {1,3};
    vector<int> vec2 = {2,6};
    vector<int> vec3 = {15, 18};
    vector<int> vec4 = {8, 10};
    vector<vector<int> > intervals;
    intervals.emplace_back(vec1);
    intervals.emplace_back(vec2);
    intervals.emplace_back(vec3);
    intervals.emplace_back(vec4);

    Solution solu;
    auto merged = solu.merge(intervals);
    return 0;
}
