class Solution
{
public:
	//topSort DFS
	void dfs(int at, vector<bool>& vis, vector<int>& nodesTraversed, unordered_map <int, vector<int>>& adj)
	{
		vis[at] = true;
		for(int i : adj[at])
		{
			if(!vis[i])
				dfs(i, vis, nodesTraversed, adj);
		}
		nodesTraversed.push_back(at);
	}

    //GRAPH COLORING to find if cycle exust (NEEDS REVISION)
	bool isCyclicDFS(unordered_map<int, vector<int>>& adj, vector<int>& v, int start)
	{
		// if(v[start] == -1)
		// 	return false;
        cout<<"start vertex : "<<start<<endl;
		v[start] = -1; // currently being visited
		// if(v[start] == 0)
		// {
			for(int i : adj[start])
			{
                // cout<<"current vertex : "<<i<<endl;

				if(v[i] == -1) //back edge detected therefore CYCLE found
					return true;

				// if(v[i] == 0)   <--- WRONG SINCE IT RETURNS TRUE TO IT's parent not out of func.
				// {
                        // isCyclicDFS(adj, v, i)
				// }

                //CORRECT
                if(v[i] == 0 && isCyclicDFS(adj, v, i))
                    return true;
			}
			v[start] = 1;
		// }
        // cout<<"are we returning false?"<<endl;
		return false;
	}

    vector<int> findOrder(int n, vector<vector<int>>& pre)
    {
    	vector<int> ans(n);

        //make adj list
        unordered_map<int, vector<int>> adj;
        for(auto v : pre)
        	adj[v[1]].push_back(v[0]);

        vector<int> v(n, 0);

        for(int i=0; i<n; ++i)
        {
            if(v[i]==0)
            {
                if(isCyclicDFS(adj, v, i))
        	        return {};
            }
        }


        vector<bool> vis(n, false);

        //start DFS here
        int i = n-1;
        for(int at=0; at<n; ++at)  //run for all nodes therefore disconnected graph taken care of
        {
        	if (!vis[at])
        	{
        		vector<int> nodesTraversed; //IMPORTANT : make temporary vector

        		dfs(at, vis, nodesTraversed, adj);

        		for(int nodeId : nodesTraversed){
        			ans[i] = nodeId;
        			--i;
        		}
        	}
        }
        return ans;

    }
};


/*
2
[[0,1],[1,0]]
4
[[1,0],[2,0],[3,1],[3,2]]
6
[[5,3], [5,2], [4,2], [3,4], [3,0], [1,3], [1,5]]


*/
        /*just printing adj list

        for(auto p : adj)
        {
        	cout << p.first<<" : ";
        	for(auto i : p.second)
        	{
        		cout<<i<<" ";
        	}
        	cout<<endl;
        }
        */
        // return ans;
