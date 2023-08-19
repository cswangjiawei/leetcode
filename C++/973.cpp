class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto compare = [](vector<int>& a, vector<int>& b) {return pow(a[0],2)+pow(a[1],2) < pow(b[0], 2)+pow(b[1], 2);};
        sort(points.begin(), points.end(), compare);
        return {points.begin(), points.begin()+k};
    }
};