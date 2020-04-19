// https://www.codewars.com/kata/5541f58a944b85ce6d00006a/
#include <vector>
#include <iostream>
#include <ios>
/*
typedef unsigned long long ull;

ull Fib(ull n);

class ProdFib
{
  public:
    static std::vector<ull> productFib(ull prod)
    {
      std::vector<ull> ans;
      ull m = 0; ull a = 0; ull b = 0;

      while((a*b) < prod)
      {
        a = Fib(m); b = Fib(m+1);
        std::cout<<m<<std::endl; std::cout<<"a: "<< a <<std::endl; std::cout<<"b: "<< b <<std::endl;
        m++;

      }
      if((a*b) == prod)
      {
        ans.push_back(a);
        ans.push_back(b);
        ans.push_back(1);
      }
      else
      {
        ans.push_back(a);
        ans.push_back(b);
        ans.push_back(0);
      }

      return ans;
    }

};

ull Fib(ull n)
{
  if(n <= 1)
    return n;
  return (Fib(n-1)+Fib(n-2));
}
*/


//------------------BEST ANS-------------------------

using ull = unsigned long long;

class ProdFib
{
  public:
    static std::vector<ull> productFib(ull prod)
    {
      ull a = 1, b = 1;

      while (a * b < prod)
      {
        ull p = a + b;
        a = b;
        b = p;
      }

      return {a, b, a * b == prod};
    }
};
