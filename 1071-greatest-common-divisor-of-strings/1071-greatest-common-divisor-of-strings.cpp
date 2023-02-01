class Solution {
 public:
  string gcdOfStrings(string a, string b) {
    if (a.size() < b.size()) swap(a, b);
    string temp = b;
    string s1, s2 = "";
    string res = "";
    while ((int)temp.size() > 0) {
      while (s1.size() < a.size()) s1 += temp;
      while (s2.size() < b.size()) s2 += temp;
      if (s1 == a && s2 == b) {
        return temp;
      }
      temp.pop_back();
      s1 = "", s2 = "";
    }
    return "";
  }
};