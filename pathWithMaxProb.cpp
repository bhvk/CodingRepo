class Solution
{
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)
    {
        unordered_map<int, vector<pair<int,double>>> adj;
        // from -> {{to, weight},{to, weight}, {to, weight}}

        for(int i=0; i<edges.size(); ++i){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        //distance vector
        vector<double> val(n, 0);
        val[start] = 1;

        //visited
        vector<bool> vis(n, false);

        priority_queue<pair<double, int>> pq ;
        pq.push({1, start});

        while(!pq.empty())
        {
            // auto a = pq.top();       --> a.first = index    |    a.second =
            int index = pq.top().second;

            // cout<<"index : "<<index<<endl;
            double probDistance = pq.top().first;
            pq.pop();
            vis[index] = true;

            // int i=0;
            for(auto paer : adj[index])
            {

                    if(vis[paer.first]) continue;

                    double newProbDistance = probDistance*paer.second;

                    if(newProbDistance > val[paer.first])
                    {
                        val[paer.first] = newProbDistance;
                        pq.push({val[paer.first], paer.first});
                    }
            }
        }

        // return 0.25;
        return val[end];

    }
};
