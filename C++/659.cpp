class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int> > > mp;
        for (int num: nums) {
            if (mp.find(num-1) != mp.end()) {
                mp[num].push(mp[num-1].top() + 1);
                mp[num-1].pop();
                if (mp[num-1].size() == 0) {
                    mp.erase(num-1);
                }
            } else {
                mp[num].push(1);
                // priority_queue<int, vector<int>, greater<int> > queue;
                // queue.push(1);
                // mp[num] = queue;
            }
        }

        for (auto& [key, val]: mp) {
            if (val.top() < 3)
                return false;
        }

        return true;
    }
};


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count_mp;
        unordered_map<int, int> end_mp;

        for (int num: nums) {
            ++count_mp[num];
        }

        for (int num: nums) {
            if (count_mp[num] == 0) continue;
            if (end_mp[num-1]) {
                ++end_mp[num];
                --end_mp[num-1];
                --count_mp[num];
            } else {
                int cnt_1 = count_mp[num+1];
                int cnt_2 = count_mp[num+2];
                if (cnt_1 && cnt_2) {
                    ++end_mp[num+2];
                    --count_mp[num];
                    --count_mp[num+1];
                    --count_mp[num+2];
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count_mp;
        unordered_map<int, int> end_mp;

        for (int num: nums) {
            ++count_mp[num];
        }

        for (int num: nums) {
            if (count_mp[num] == 0) continue;
            if (end_mp[num-1]) {
                ++end_mp[num];
                --end_mp[num-1];
                --count_mp[num];
            } else {
                int cnt_1 = count_mp[num+1];
                int cnt_2 = count_mp[num+2];
                if (cnt_1 && cnt_2) {
                    ++end_mp[num+2];
                    --count_mp[num];
                    --count_mp[num+1];
                    --count_mp[num+2];
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};