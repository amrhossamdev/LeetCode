class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    int n = s.size();
    vector<int> freq(26, 0);
    vector<int> freq2(26, 0);
    for (int i = 0; i < p.size(); ++i) {
      freq2[p[i] - 'a']++;
    }
    int l = 0, r = 0;
    int cnt = 0;
    while (l < n) {
      while (r < n && cnt < p.size()) {
        freq[s[r++] - 'a']++;
        ++cnt;
      }
      if (cnt >= p.size()) {
        if (freq == freq2) {
          ans.push_back(l);
        }
        --cnt;
      }
      freq[s[l] - 'a']--;
      l++;
    }
    return ans;
  }
};