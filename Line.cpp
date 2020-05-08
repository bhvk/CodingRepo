class Solution
{
public:
    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
        if(coordinates.size() == 2)
          return true;

        long x1 = coordinates[0][0]; long x2 = coordinates[1][0];
        long y1 = coordinates[0][1]; long y2 = coordinates[1][1];
        double m; double c;

        if (x1==x2)
        {
            for(auto p : coordinates)
            {
              if(p[0] != x1)
                return false;
            }
            return true;
        }
        else if(y1==y2)
          m=0;

        else
          m = (y1-y2)/(x1-x2);

        c = (y1-m*x1);

        for(auto k : coordinates)
        {
              if(k[1] != m*k[0] + c)
                return false;
        }

        return true;
    }
};
