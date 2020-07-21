class Solution
{
public:
    int R, C;
    int len;
    bool dfs(int i, int j, vector<vector<char>>& g, vector<vector<bool>> &vis, int x, string &s)
    {
        if (x >= len || i < 0 || j < 0 || i >= R || j >= C || vis[i][j] || s[x] != g[i][j])
            return false;

        // cout<<s[x]<<endl;

        //if last char of string and matches cell of current grid : return true
        if(x == len-1 && !vis[i][j] && g[i][j] == s[len-1])
            return true;


        vis[i][j] = true;

        if(x+1<len)
        {
            if(dfs(i-1, j, g, vis, x+1, s) || dfs(i, j+1, g, vis, x+1, s) || dfs(i, j-1, g, vis, x+1, s) || dfs(i+1, j, g, vis, x+1, s))
                return true;
        }

        vis[i][j] = false; // VERY VERY IMPORTANT TO MARK IT AS UNVISITED POST DFS DUE TO BACKTRACKING CAN THIS GRID CELL CAN BE USED IN NEXT DFS CALL
        return false;

    }
    bool exist(vector<vector<char>>& g, string str)
    {
        bool ans = false;
        R = g.size();
        C = g[0].size();
        len = (int)str.size();
        vector<vector<bool>> vis(g.size(), vector<bool>(g[0].size(), false));


        for(int i=0; i<R; ++i)
        {
            for(int j=0; j<C; ++j)
            {
                if(!vis[i][j] && str[0] == g[i][j])
                    ans = dfs(i, j, g, vis, 0, str);
                if(ans)
                    break;
                // vis = vector<vector<bool>>(R, vector<bool>(C, false)); ?? BAD IDEA -__-
            }
            if(ans)
                break;
        }
        return ans;
    }
};
/*
[["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
"ABCESEEEFS"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCCED"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"SEE"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCB"
[["C","A","A"],["A","A","A"],["B","C","D"]]
"AAB"
*/
