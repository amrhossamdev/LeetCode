class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<char, int> freq;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      freq[s[i]]++;
    }
    string ans = "";
    for(auto i : freq){
      char mx = 'a';
      int cnt = 0;
      for(auto &j : freq){
        if (j.second > cnt) {
          cnt = j.second;
          mx = j.first;
        }
      }
      freq[mx] = 0;
      while (cnt--) {
        ans += mx;
      }
    }
    return ans;
  }
};