/*OPEN THE LOCK : (BFS)*/
/*taken from Nick White : https://www.youtube.com/watch?v=IHT8Sx0832k*/

#define LENGTH 4
class Solution
{
public:
    int openLock(vector<string>& deadends, string target)
    {
        unordered_set<string> dends(deadends.begin(), deadends.end());
        queue<string> q;
        string s = "0000";
        q.push(s);
        unordered_set<string> visited;
        visited.insert(s);

        int count = 0;
        while(!q.empty())
        {
            int l = q.size();
            while(l>0)
            {
                string curr_lock = q.front();
                q.pop();
                if(dends.find(curr_lock) != dends.end())
                {
                    l--;
                    continue;
                }
                // cout<<"curr_lock : "<<curr_lock<<endl;
                // cout<<"target : "<<target<<endl;
                if(curr_lock == target)
                    return count;

                for(int i=0; i<LENGTH; ++i)
                {
                    string s1 = curr_lock;
                    string k = to_string(s1[i] == '9' ? 0 : (s1[i] - '0')+1);
                    s1.replace(i,1,k);
                    // cout<<"s1 : "<<s1<<endl;



                    string s2 = curr_lock;
                    string m = to_string(s2[i] == '0' ? 9 : (s2[i] - '0')-1);
                    s2.replace(i,1,m);
                    // cout<<"s2 : "<<s2<<endl<<endl;

                    if(visited.find(s1) == visited.end() && dends.find(s1) == dends.end()){
                        q.push(s1);
                        visited.insert(s1);
                    }
                    if(visited.find(s2) == visited.end() && dends.find(s2) == dends.end()){
                        q.push(s2);
                        visited.insert(s2);
                    }
                }
                l--;
            }
            ++count;
        }
        return -1;
    }
};


//******************************************************************************

/* BFS Template */
int level = START; //0 or 1 or whatever
while(!q.empty())
{
    int sz = q.size();
    while(sz>0)
    {
        //computation and logics add to queue
        //add to visited array/vector
        sz--;
    }
    ++level;
}
return level;
