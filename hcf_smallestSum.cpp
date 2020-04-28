//https://www.codewars.com/kata/52f677797c461daaf7000740/

#include <vector>
typedef unsigned long long ull;
/* //This hcfUtility times out (inefficient)
ull hcfUtility(ull a, ull b)
{
    if (a == 0)
       return b;
    if (b == 0)
       return a;
    // base case
    if (a == b)
        return a;
    // a is greater
    if (a > b)
        return hcfUtility(a-b, b);
    return hcfUtility(a, b-a);
}
*/
ull hcfUtility(ull a , ull b)
{
   if(b==0) return a;
   // a%=b; // a=a%b;
   a=a%b;
   return hcfUtility(b,a);
}
ull findHCF(std::vector<ull>& arr)
{
  ull hcf = -9;
  if(arr.size() == 1)
    hcf = arr[0];
  else
  {
    hcf = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
    {
      hcf = hcfUtility(hcf, arr[i]);
      if(hcf == 1)
        break;
    }
  }
  return hcf;
}

unsigned long long solution(const std::vector<unsigned long long>& array)
{
  std::vector<ull> arr{array};
  /*because :  NOTE: candidate function not viable: 1st argument ('const std::vector<unsigned long long>') would lose const qualifier
ull findHCF(std::vector<ull>& arr)*/

  ull ans = -1;
  if(arr.empty())
    return 0;

  ull hcf = findHCF(arr);

  std::cout << "HCF : "<< hcf << '\n';

  ans = (arr.size())*hcf;

  return ans;
}


/*
BEST solution
#include <vector>

unsigned long long solution(const std::vector<unsigned long long>& arr) {
    unsigned long long cur_gcd = arr.front();

    for(auto num : arr){
        cur_gcd = std::__gcd(num, cur_gcd);

    }
    return cur_gcd * arr.size();
}
*/
