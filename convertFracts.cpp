#include <numeric>

class Fracts
{

public:
    static std::string convertFrac(std::vector<std::vector<unsigned long long>> &lst);
};

std::string Fracts::convertFrac(std::vector<std::vector<unsigned long long>> &lst)
{
    std::string ans="";
    typedef unsigned long long ull;

    ull lcmAns = 1;
    for (size_t i = 0; i < lst.size(); i++)
    {
      // ull b = lst[i][1];
      lcmAns = std::lcm(lcmAns, lst[i][1]);
    }

    for(size_t i=0; i<lst.size();i++)
    {
      ull k = (lcmAns/(lst[i][1]))*(lst[i][0]);
      ans += "("+std::to_string(k)+","+std::to_string(lcmAns)+")";
    }
    return ans;
}
