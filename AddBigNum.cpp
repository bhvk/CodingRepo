// Example program
#include <iostream>
#include <string>
#include<bits/stdc++.h>
#include<algorithm>

std::string add(const std::string& a, const std::string& b)
{
  std::string ans = "";

  std::cout<< a << std::endl << b << std::endl;
  std::string numA(a.rbegin(), a.rend());
  std::string numB(b.rbegin(), b.rend());
  std::cout<< numA << std::endl << numB << std::endl;

  int lenA =numA.size();
  int lenB =numB.size();

  int n = (lenA>lenB)?lenA:lenB;
  std::cout<< n << std::endl;

  if((lenA) < (lenB))
  {
    for(int i=lenA+1; i<=n; i++)
      numA = numA+'0';
  }

  if((lenA) > (lenB))
  {
    for(int i=lenB+1; i<=n; i++)
      numB = numB+'0';
  }

  std::cout<< numA << std::endl << numB << std::endl;

  int carry =0;
  for (int i = 0; i < n; i++)
  {
    int digA = numA[i]-'0';
    int digB = numB[i]-'0';
    int sum = digA+digB+carry;
    carry = sum/10;
    int digAns = sum%10;
    ans = ans+std::to_string(digAns);
  }

  if(carry)
    ans = ans+ std::to_string(carry);
  //reverse final ans
  std::reverse(ans.begin(), ans.end());
  //return
  return ans;
}

int main()
{
  std::string numA("2432") ;
  std::string numB("1752986") ;

//   std::cout<< numA << std::endl << numB << std::endl;
//   int x = numA[0] - '0';
//   std::cout<< x<<std::endl;
  std::string ans = add(numA, numB);
  std::cout<< ans<< std::endl;;
}
