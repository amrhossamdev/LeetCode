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
      if (i.second == 1) return -1;
      int tmp = i.second;
        cout << i.first << " " << i.second << endl;
      if (tmp > 4) {
        if (tmp % 3 == 2) {
          ans += tmp / 3;
          tmp -= (tmp / 3) * 3;
        } else if (tmp % 3 == 1) {
          ans += (tmp / 3) - 1;
          tmp -= ((tmp / 3) - 1) * 3;
        }else{
            ans+=tmp/3;
            tmp = 0;
        }
      }
        ans += tmp / 2;
      
    }
    return ans;
  }
};