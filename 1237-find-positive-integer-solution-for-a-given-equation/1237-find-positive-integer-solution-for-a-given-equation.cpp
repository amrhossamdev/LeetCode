/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector <vector<int>> findSolution(CustomFunction &customfunction, int z) {
        int prev = -1;
        vector <vector<int>> ans;
        for (int i = 1; i <= 1000; i++) {
            for (int j = 1; j <= 1000; ++j) {
                if (prev == -1 && customfunction.f(i, j) == z) {
                    ans.push_back({i, j});
                    prev = customfunction.f(i, j);
                } else {
                    if (prev != -1 && prev <= customfunction.f(i, j) && customfunction.f(i, j) == z) {
                        prev = customfunction.f(i, j);
                        ans.push_back({i, j});
                    }
                }
            }
        }
        return ans;
    }
};