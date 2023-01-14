class Solution {
 public:
  struct DSU {
    vector<int> par;
    void init(int n) {
      par = vector<int>(n + 1);
      for (int i = 1; i <= n; ++i) {
        par[i] = i;
      }
    }
    int findparent(int u) {
      if (par[u] == u) return u;
      return par[u] = findparent(par[u]);
    }
    int merge(int u, int v) {
      u = findparent(u);
      v = findparent(v);
      if (u == v) return -1;
      if (u < v) {
        par[v] = u;
      } else {
        par[u] = v;
      }
      return 0;
    }
  };

  string smallestEquivalentString(string s1, string s2, string baseStr) {
    int n = s1.size();
    DSU ds;
    ds.init(26);
    for (int i = 0; i < n; ++i) {
      ds.merge(s1[i] - 'a', s2[i] - 'a');
    }
      
    string ans;
    for (char &c : baseStr) {
      ans += (char)(ds.findparent(c - 'a') + 'a');
    }
    return ans;
  }
};