//https://www.codewars.com/kata/54d496788776e49e6b00052f

#include <string>
#include <vector>
#include <cstdlib> //for abs()
#include <cmath>  //for sqrt()

class SumOfDivided
{
  public:
      //********************CLASS FUNCTION 1***************************
      static std::string sumOfDivided(std::vector<int> &lst)
      {
        for(auto m : lst)
          std::cout << m <<" ";  //DELETE cout
        std::cout<<"\n\n";

        std::string ans="";
        std::vector<int> pfl;

        //GETTING PRIME FACTORS LIST
        for (size_t i = 0; i < lst.size(); i++)
        {
          if(lst[i] == 1)
            pfl.push_back(1);
          if(abs(lst[i]) >=2)
            getPFL(abs(lst[i]), pfl);
        }

        //CLEANING
        // Sorting the array
        std::sort(pfl.begin(), pfl.end());
        // Using std::unique
        int l = pfl.size();
        std::vector<int>::iterator ip;
        ip = std::unique(pfl.begin(), pfl.begin() + l);
        // Resizing the vector so as to remove the undefined terms
        pfl.resize(std::distance(pfl.begin(), ip));

        for(auto j : pfl)
          std::cout << j <<" ";  //DELETE cout
        std::cout<<"\n\n";

        //FINAL PRINTING of answer
        for (size_t i = 0; i < pfl.size(); i++)
        {
          int sum = 0;
          for (size_t j = 0; j < lst.size(); j++)
          {
            if((lst[j]%pfl[i]) == 0)
              sum+= lst[j];
          }
          ans += "("+std::to_string(pfl[i])+" "+std::to_string(sum)+")";
        }

        return ans;
      }


      //********************CLASS FUNCTION 2***************************
      static void getPFL(int n, std::vector<int> &pfl)
      {
        int x = n;
        while (x % 2 == 0)
        {
          pfl.push_back(2);
          x = x/2;
        }
        // std::cout<<"now odd x is :"<< x<<"\n";
        // n must be odd at this point. So we can skip
        // one element (Note i = i +2)
        for (int i = 3; i <= sqrt(x); i = i + 2)
        {
          // While i divides n, print i and divide n
          while (x % i == 0)
          {
            pfl.push_back(i);
            x = x/i;
          }
        }
        // std::cout<<"Is x now prime? :"<< x<<"\n";
        // This condition is to handle the case when n is a prime number greater than 2
        if (x > 2)
          pfl.push_back(x);
      }


};

//To get all prime factors of a number
/*
static void getPFL(int n, std::vector<int> &pfl)
{
  int x = n;
  while (x % 2 == 0)
  {
    pfl.push_back(2);
    x = x/2;
  }
  cout<<"now odd x is :"<< x<<"\n";
  // n must be odd at this point. So we can skip
  // one element (Note i = i +2)
  for (int i = 3; i <= sqrt(x); i = i + 2)
  {
    // While i divides n, print i and divide n
    while (x % i == 0)
    {
      pfl.push_back(i);
      x = x/i;
    }
  }
  cout<<"now prime n is :"<< n<<"\n";
  // This condition is to handle the case when n is a prime number greater than 2
  if (x > 2)
    pfl.push_back(x);
}
*/
