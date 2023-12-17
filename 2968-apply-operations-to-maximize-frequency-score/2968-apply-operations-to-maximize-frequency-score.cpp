class Solution {
public:

    long long cost(int idx, int L, int R, vector<long long> &pre, vector<int> &v, long long &k) {
        // left = a[3] * (a[1] + a[2])
        // right  pre[r] - 
        // a1,a2,a3,a4,a5
        long long left = abs((idx - L + 1) * 1LL*v[idx] - (pre[idx] - (L > 0 ? pre[L - 1] : 0)));// left 
        long long right = pre[R] - pre[idx] - (R-idx) *1LL *  v[idx];
        return left + right;
    }

    bool check(int mid, vector<long long> &pre, vector<int> &v, long long &k) {

        for (int i = 0; i+mid-1 < v.size(); ++i) {
            int L = i;
            int R = i + mid - 1;
            if (cost(L + (mid/ 2), L, R, pre, v, k) <= k) {
                return true;
            }
            if (mid % 2 == 0) {
                if (cost(L + (mid / 2) - 1, L, R, pre, v, k) <= k) {
                    return true;
                }
            }

        }
        return false;
    }

    int maxFrequencyScore(vector<int> &v, long long k) {
        int n = v.size();
        sort(v.begin(), v.end());
        int l = 1, r = n;
        long long ans = 0;
        vector<long long> pre(n);
        pre[0] = v[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] + v[i];
        }
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid, pre, v, k)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;

    }
};