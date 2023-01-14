class Solution {
 public:
  struct DSU {
    vector<int> par;
    vector<int> sz;
    void init(int n) {
      par = vector<int>(n + 1);
      sz = vector<int>(n + 1, 1);
      for (int i = 1; i <= n; ++i) {
        par[i] = i;
      }
    }

    int findparent(int u) {
      if (par[u] == u) return u;
      return par[u] = findparent(par[u]);
    }
    bool isConnected(int u, int v) {
      u = findparent(u);
      v = findparent(v);
      if (u == v) return true;
      return false;
    }
    char getMin(int u) {
      int mn = INT_MAX;
      int pr = findparent(u);
      for (int i = 0; i < par.size(); ++i) {
        if (pr == par[i]) {
          mn = min(mn, i);
        }
      }
      return char(mn);
    }
    int merge(int u, int v) {
      u = findparent(u);
      v = findparent(v);
      if (u == v) return -1;
      if (sz[v] > sz[u]) swap(u, v);
      par[v] = u;
      sz[u] += sz[v];
      return 0;
    }
  };

  string smallestEquivalentString(string s1, string s2, string baseStr) {
    int n = s1.size();
    DSU ds;
    ds.init(250);
    for (int i = 0; i < n; ++i) {
      ds.merge(s1[i], s2[i]);
    }
    for (int i = 0; i < baseStr.size(); ++i) {
      int ch = ds.getMin(baseStr[i]);
      if (baseStr[i] > ch) {
        baseStr[i] = ch;
      }
    }
    return baseStr;
  }
};