class Solution {
 public:
  vector<int> sortEvenOdd(vector<int> &nums) {
    vector<int> e, o;
    for (int i = 0; i < nums.size(); ++i) {
      if (i % 2 != 0)
        o.push_back(nums[i]);
      else
        e.push_back(nums[i]);
    }
    sort(e.begin(), e.end());
    sort(o.rbegin(), o.rend());

    int x = 0, y = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i % 2 == 0) {
        nums[i] = e[x++];
      } else {
        nums[i] = o[y++];
      }
    }

    return nums;
  }
};