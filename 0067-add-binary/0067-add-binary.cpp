class Solution {
 public:
  string addBinary(string a, string b) {
    string s = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int c = 0;
    while (i >= 0 || j >= 0) {
      int x = i >= 0 ? (a[i] - '0') : 0;
      int y = j >= 0 ? (b[j] - '0') : 0;
      int z = x + y + c;
      c = z / 2;
      z = z % 2;
      s += to_string(z);
      i--;
      j--;
    }
    if (c == 1) s += "1";
    reverse(s.begin(), s.end());
    return s;
  }
};