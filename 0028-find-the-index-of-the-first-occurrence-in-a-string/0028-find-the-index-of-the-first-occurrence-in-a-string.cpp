class Solution {
public:
    const int N = 1e4 + 5;
const long long mod = 1e9 + 7, mod2 = 1e9 + 9;
const int INF = 2e9;
const int p = 31, p2 = 37;
 long long pw[10005], pref[10005], inv[10005];
 long long pw2[10005], pref2[10005], inv2[10005];


 long long mul(long long a, long long b, long long m) {
    return 1LL * a * b % m;
}
    
    long long  add(long long  a, long long  b, long long  m) {
    return (a + b) % m;
}

 long long fp( long long b,  long long p,  long long m) {
    long long ans = 1;
    while (p) {
        if (p & 1) ans = mul(ans, b, m);
        b = mul(b, b, m);
        p /= 2;
    }
    return ans;
}


void pre() {

    pw[0] = 1, inv[0] = 1;
    pw2[0] = 1, inv2[0] = 1;
    int mul_inv = fp(p, mod - 2, mod);
    int mul_inv2 = fp(p2, mod2 - 2, mod2);

    for (int i = 1; i < N; i++) {
        pw[i] = mul(p, pw[i - 1], mod);
        inv[i] = mul(mul_inv, inv[i - 1], mod);
        pw2[i] = mul(p2, pw2[i - 1], mod2);
        inv2[i] = mul(mul_inv2, inv2[i - 1], mod2);
    }
}

int getHash(string &st) {
    for (int i = 0; i < st.size(); i++) {
        pref[i + 1] = mul((st[i] - 'a' + 1), pw[i], mod);
        pref[i + 1] = add(pref[i], pref[i + 1], mod);
        pref2[i + 1] = mul((st[i] - 'a' + 1), pw2[i], mod2);
        pref2[i + 1] = add(pref2[i], pref2[i + 1], mod2);
    }
    return pref[st.size()];
}

pair<int, int> getHashRange(int L, int R) {
    return {mul(add(pref[R], mod - pref[L - 1], mod), inv[L - 1], mod),
            mul(add(pref2[R], mod2 - pref2[L - 1], mod2), inv2[L - 1], mod2)};
}

    int strStr(string s1, string s2) {
        int n = s1.size();
        int m =s2.size();
        if(m > n)return -1;
        pre();
        getHash(s2);
        auto neddleHash = getHashRange(1,m);
        auto hash = getHash(s1);
      
        for(int i =0;i<n;++i){
            int l =i + 1, r = i + m;
            if(r > n) break;
            if(getHashRange(l,r) == neddleHash) return i;
        }
        return -1;
    }
};