class Solution {
 public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> ans;
    for (int i = 1; i <= 9; ++i) {
      string tmp;
      for (int j = i; j <= 9; ++j) {
        tmp += to_string(j);
        int x = stoi(tmp);
        if (x >= low && x <= high) {
          ans.push_back(x);
        }
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};