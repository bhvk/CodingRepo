#include <utility>
#include <vector>
#include <cmath>

class SumSquaredDivisors
{
public:
    static std::vector<std::pair<long long, long long>> listSquared(long long m, long long n)
    {
      std::vector<std::pair<long long, long long>> result;

      for (long long i = m; i <=n ; i++)
      {
        /* code */
        std::vector<long long> divisorsList = ListOfDivisors(i);
        long long sum = sumOfSquaredDivisors(divisorsList);
        bool ans = isSquare(sum);

        if(ans)
        {
          // result.push_back([i, sum]);  //wrong way to push_back since push_back takes only 1 arguement
          result.push_back(std::make_pair(i,sum));
        }
      }
      return result;
    }
    //Function 1
    static std::vector<long long> ListOfDivisors(long long x)
    {
      std::vector<long long> divs;
      // int k = 1;
      divs.push_back(1);
      for(long long k=2; k<=x; k++)
      {
        if(x%k == 0)
          divs.push_back(k);
      }
      return divs;
    }
    //Function 2
    static long long sumOfSquaredDivisors(std::vector<long long> divList)
    {
      long long ans = 0;
      for(int i =0; i<divList.size(); i++)
      {
        ans = ans + (divList[i]*divList[i]);
      }
      return ans;
    }
    //Function 3
    static bool isSquare(long long sum)
    {
      // long long sr = std::sqrt(sum);
      long double sr = std::sqrt(x);
      return ((sr - std::floor(sr)) == 0);
    }
};
