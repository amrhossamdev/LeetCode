class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start = 0, totalCost = 0, totalTank = 0;
    int n = cost.size();
    for (int i = 0; i < n; ++i) {
      totalCost += cost[i];
      totalTank += gas[i];
    }
    if (totalCost > totalTank) return -1;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      cur += gas[i] - cost[i];
      if (cur < 0) {
        start = i + 1;
        cur = 0;
      }
    }
    return start;
  }
};