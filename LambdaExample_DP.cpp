//PROBLEM : https://leetcode.com/problems/make-array-strictly-increasing/description/
#include<vector>

using namespace std;
class Solution {
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
        std::sort(arr2.begin(), arr2.end());
        vector<vector<int>> dp(arr1.size() + 1, vector<int>(arr2.size() + 1, -1));
        auto solve = [&](auto &&solve, int i, int j, int prev) -> int {
            if (i >= arr1.size()) {
                return 0;
            }
            j = upper_bound(arr2.begin() + j, arr2.end(), prev) - arr2.begin();
            if (arr2.size() <= j && arr1[i] < prev) {
                return 3000;
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            int take_swap = 3000, notake = 3000;
            if (j < arr2.size()) {
                take_swap = 1 + solve(solve, i + 1, j + 1, arr2[j]);
            }
            if (arr1[i] > prev) {
                notake = solve(solve, i + 1, j, arr1[i]);
            }
            return dp[i][j] = min(take_swap, notake);
        };
        int res = solve(solve, 0, 0, -1);
        return res <= arr1.size() ? res : -1;
    }
};