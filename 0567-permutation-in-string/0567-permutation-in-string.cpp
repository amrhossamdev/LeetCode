class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    vector<int> s1Count(26, 0);
    vector<int> s2Count(26, 0);
    int l = 0, r = s1.size()-1;
    for (int i = 0; i < s1.size(); ++i) {
      s1Count[s1[i] - 'a']++;
      s2Count[s2[i] - 'a']++;
    }

    while (r < s2.size()) {
      if (s1Count == s2Count) return true;
      r++;
      if (r != s2.size()) {
        s2Count[s2[r] - 'a']++;
      }
      s2Count[s2[l] - 'a']--;
      l++;
    }
    return false;
  }
};