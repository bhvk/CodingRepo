static auto fastio = [](){
  // turn off sync
    std::ios::sync_with_stdio(false);
  // untie in/out streams
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        vector<vector<pair<int,int>>> adj(n);
        //size to be provided else you get "runtime error: reference binding to null pointer of type "std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >' (stl_vector.h)"
        for(auto &i : flights)
        {
            adj[i[0]].push_back(make_pair(i[1], i[2])); //{from : {to , cost}}
            //can also use this syntax :  adj[i[0]].push_back({i[1], i[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>Q; // class T, class container, class compare = greater<typename container::value_type>
        //The behavior is undefined if T is not the same type as Container::value_type

        // Syntax to create a min heap for priority queue : priority_queue <int, vector<int>, greater<int>> g = gq;
        Q.push({0, src, K+1}); //(distance, source, number of edges (i.e hops+1))  because 1 stop means 3 vertices total and 2 edges (src->hop->dst)
        // while (!Q.empty())
        while(!Q.empty())
        {
            vector<int> top = Q.top();
            Q.pop();
            int d = top[0]; //distance
            int u = top[1]; //source
            int e = top[2]; //edge wt.
            if(u == dst) return d; //if the current vertex is our dst (destination), so return

            if(e>0) //btw only postive edges are given
            {
                for(pair<int,int> &v : adj[u])
                    Q.push({d+v.second, v.first, e-1});
            }
        }
        return -1;
    }
};
