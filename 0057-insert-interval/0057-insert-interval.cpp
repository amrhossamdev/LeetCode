class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    int n = intervals.size();
    vector<vector<int>> ans;
    bool inserted = false;

    for (vector<int> interval : intervals) {
      if (interval[1] < newInterval[0]) {
        // Before newInterval
        ans.push_back(interval);
        continue;
      } else if (interval[0] > newInterval[1]) {
        // After newInterval
        if (!inserted) {
          ans.push_back(newInterval);
          inserted = true;
        }
        ans.push_back(interval);
      } else {
        // merge intervals
        newInterval[0] = min(newInterval[0], interval[0]);
        newInterval[1] = max(newInterval[1], interval[1]);
      }
    }
    if (!inserted) {
      ans.push_back(newInterval);
    }
    return ans;
  }
};