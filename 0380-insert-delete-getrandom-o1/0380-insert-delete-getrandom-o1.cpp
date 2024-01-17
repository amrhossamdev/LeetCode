class RandomizedSet {
 public:
  map<int, int> mp;
  vector<int> tmp;
  RandomizedSet() {}

  bool insert(int val) {
    if (mp.find(val) != mp.end()) return false;
    tmp.push_back(val);
    mp[val] = tmp.size() - 1;
    return true;
  }

  bool remove(int val) {
    if (mp.find(val) == mp.end()) return false;
    int last = tmp.back();
    tmp[mp[val]] = tmp.back();
    tmp.pop_back();
    mp[last] = mp[val];
    mp.erase(val);
    return true;
  }

  int getRandom() { return tmp[rand() % tmp.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */