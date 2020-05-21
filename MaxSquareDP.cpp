//DP
//https://leetcode.com/problems/maximal-square
class Solution
{
public:
    int maximalSquare(vector<vector<char>>& a)
    {
        int ans = 0;
        int r = a.size();
        if(r == 0 || a[0].empty())
            return ans;

        int c = a[0].size();
        vector<vector<int>>dp(r, vector<int>(c));

        for(int i=0; i<r; ++i)
        {
            for(int j=0; j<c; ++j)
            {
                if(a[i][j] == '1')
                {
                    dp[i][j] = 1;

                    if(i>0 && j>0)
                    {
                        dp[i][j] += min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}); //note min of more than 2 elements use min({a,b,c});
                        // ans = max(dp[i][j], ans);
                    }
                    ans = max(dp[i][j], ans);
                }
            }
            // for(auto k : dp)
            // {
            //     for(auto i: k)
            //         cout<<i<<", ";
            //     cout << endl;
            // }
        }
        return ans*ans;
    }
};
