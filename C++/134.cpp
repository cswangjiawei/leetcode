class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int count = 0;
        int start = 0;
        int n = gas.size();
        int remain_gas = 0;

        while (start < n) {
            remain_gas = 0;
            count = 0;
            for (int i=start%n; count!=n; ) {
                remain_gas += (gas[i] - cost[i]);

                if (remain_gas<0) {
                    break;
                }
                ++count;
                if (count == n) {
                    return start;
                }
                i = (i+1) % n;
            }
            start = (start+count+1);
        }

        return -1;
    }
};