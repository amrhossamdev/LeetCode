class Solution {
 public:
  int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }
  int subarrayGCD(vector<int>& v, int k) {
    int n = v.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int res = v[i];
      for (int j = i; j < n; ++j) {
        res = gcd(res, v[j]);
        if (res != k)
          continue;
        else {
          ans++;
        }
      }
    }

    return ans;
  }
};