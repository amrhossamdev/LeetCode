class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        unordered_map<string, int> mp;
        sort(tiles.begin(),tiles.end());
        do {
            for (int msk = 0; msk < (1 << n); ++msk) {
                string s= "";
                for (int i = 0; i < n; ++i) {
                    if ((msk & (1 << i))) {
                        s += tiles[i];
                    }
                }
                if(!s.empty())mp[s]++;
            }
        } while (next_permutation(tiles.begin(), tiles.end()));

        return mp.size();
    }
};