class ParkingSystem {
 public:
  unordered_map<int, int> mp;
  ParkingSystem(int big, int medium, int small) {
    mp[3] = small;
    mp[2] = medium;
    mp[1] = big;
  }

  bool addCar(int v) {
    if (v == 1 && mp[1] > 0) {
      mp[1]--;
      return true;
    } else if (v == 2 && mp[2] > 0) {
      mp[2]--;
      return true;
    } else if (v == 3 && mp[3] > 0) {
      mp[3]--;
      return true;
    } else {
      return false;
    }
  }
};
