class Solution {
 public:
  int bagOfTokensScore(vector<int> &tokens, int power) {
    int score = 0;
    int n = tokens.size();
    int l = 0, r = n - 1;
    int ans = 0;
    sort(tokens.begin(), tokens.end());
    while (l <= r) {
      if (power >= tokens[l]) {
        power -= tokens[l++];
        score++;
      } else {
        if (score) {
          power += tokens[r];
          score--;
        }
        r--;
      }
      ans = max(score, ans);
    }

    return ans;
  }
};