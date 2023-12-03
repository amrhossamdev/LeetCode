class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int sz = flowerbed.size();
    if (sz >= 2) {
      if (!flowerbed[0] && !flowerbed[1]) {
        n--;
        flowerbed[0] = 1;
      }
      if (!flowerbed[sz - 1] && !flowerbed[sz - 2]) {
        n--;
        flowerbed[sz - 1] = 1;
      }
    } else if (sz == 1) {
      if (!flowerbed[0]) {
        n--;
      }
    }
    for (int i = 1; i < sz - 1; ++i) {
      if (!flowerbed[i - 1] && !flowerbed[i] && !flowerbed[i + 1]) {
        n--;
        flowerbed[i] = 1;
      }
    }
    return n <= 0;
  }
};