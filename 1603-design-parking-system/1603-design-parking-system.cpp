class ParkingSystem {
 public:
  map<int, int> mp;
  ParkingSystem(int big, int medium, int small) {
    mp[3] = small;
    mp[2] = medium;
    mp[1] = big;
  }

  bool addCar(int v) {
    if (mp[v] > 0) {
      mp[v]--;
      return true;
    }
    return false;
  }
};
