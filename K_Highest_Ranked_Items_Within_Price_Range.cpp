//NOTE : using
// vector<array<int,4>> v;  instead of vector of vector of int(s)
// and also using
// vector<vector<char>>vis; instead of  vector of vector of bool(s)
// for faster processing

// #define PRINT
int R[4] ={1,-1, 0, 0};
int C[4] ={0, 0, 1, -1};
class Solution {
public:
    bool valid(int x, int y, vector<vector<int>>& grid, vector<vector<char>>& vis, vector<int>& p, int k)
    {
        if(x >=0 and x<grid.size() and y>=0 and y<grid[0].size() and vis[x][y] == 'f' and grid[x][y]!= 0)// and grid[x][y]<=p[1])
            return true;
        return false;
    }
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& p, vector<int>& s, int k)
    {
        vector<vector<int>> ans;
        int d = 0;

        // vector<pair<int, vector<int>> finalList;
        // vector<pair < pair<int,int>, vector<int> >> finalList;
        vector<array<int, 4>> finalList;
        vector<vector<char>> vis(grid.size(), vector<char>(grid[0].size(), 'f'));

        vis[s[0]][s[1]] = true;

        //data-structure to store visited node for BFS

        // queue<pair < pair<int,int>, vector<int> >> q; //{{dist, cost}, [x,y] }
        // queue<vector<int>> q;
        queue<array<int, 4>> q;
        // q.push({{0, grid[s[0]][s[1]]}, s});
        q.push({0, grid[s[0]][s[1]], s[0], s[1]});
        //{dist, cost, x, y}

        // BFS
        while(!q.empty())
        {
            d++;
            // cout<<"Distance = "<<d<<endl;
            int sz = q.size();

            while(sz)
            {
                auto f = q.front();
                q.pop();
#ifdef PRINT
                cout<<"{";
                for(auto i : f)
                {
                    cout<<i<<", ";
                }
                cout<<"}"<<endl;
                cout<<"X : "<<f[2]<<", Y : "<<f[3]<<endl;
#endif
                if(f[1]>=p[0] and f[1]<=p[1])
                    finalList.push_back(f);

                for(int i=0; i<4; ++i)
                {
                    int x = f[2];
                    int y = f[3];
                    x+= R[i]; y += C[i];
                    if(valid(x, y, grid, vis, p, k))
                    {
                        q.push({d, grid[x][y], x, y});
                        vis[x][y] = 't';
                    }
                }
                sz--;
            }
        }

        // cout<<"FINAL LIST SZ = "<<finalList.size()<<endl;
        // sort(begin(finalList), end(finalList), [](const vector <int> &a, const vector <int> &b){
        sort(begin(finalList), end(finalList), [](const array <int,4> &a, const array <int,4> &b){
            if(a[0] == b[0])  //distsance same
            {
              if(a[1] == b[1])
              {
                if(a[2] == b[2])
                {
                  return a[3]<b[3];
                }
                return a[2]<b[2];
              }
              return a[1]<b[1];
            }
            return a[0]<b[0];
        });

        for(int i=0; i<finalList.size() and i<k; ++i)
            ans.push_back({finalList[i][2], finalList[i][3]});

        return ans;

    }
};
