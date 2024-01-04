class Solution {
 public:
  int minOperations(vector<int> &v) {
    map<int, int> mp;
    int n = v.size();
    for (int i = 0; i < n; ++i) {
      mp[v[i]]++;
    }

    int ans = 0;
    for (auto i : mp) {
      int freq = i.second;
      if (freq == 1) return -1;
      if (freq > 4) {
        if (freq % 3 == 2) {
          ans += freq / 3;
          freq -= (freq / 3) * 3;
        } else if (freq % 3 == 1) {
          ans += (freq / 3) - 1;
          freq -= ((freq / 3) - 1) * 3;
        } else {
          ans += freq / 3;
          freq = 0;
        }
      }
      ans += freq / 2;
    }
    return ans;
  }
};