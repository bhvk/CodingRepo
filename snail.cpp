//SNAIL codewars: //https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1/
//2-D Vector traversal in snail fashion.
#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &a)
{
    int n = a.size();
    int i=0, j=0;
    int total= (n*n), steps = n, dir=0;
    std::cout << "steps :" <<steps<< '\n'<<"total : "<< total<<"\n";

    std::vector<int> ans;

    if(a[0].empty())
    {
      std::cout << "EMPTY"<<"\n";
      return ans;
    }
    //dir L->R = 0, U->D = 1, R->L = 2, D->U = 3;
    while(total) //total num of steps
    {
        int c = 0;
        while (c < steps) //keep walking unless nothing further to walk in that direction
        {
            if(dir == 0) //dir : L->R
            {
              ans.push_back(a[i][j]);
              j++;
            }
            else if(dir == 1) //dir : U->D
            {
              ans.push_back(a[i][j]);
              i++;
            }
            else if(dir == 2) //dir : R->L
            {
              ans.push_back(a[i][j]);
              j--;
            }
            else if(dir == 3) //dir : D->U
            {
              ans.push_back(a[i][j]);
              i--;
            }
            else
            {
              std::cout << "SHOULD NOT BE HERE!" << '\n';
            }
            total--;
            c++;
        }//end of INNER while loop

        //outer loop continued
        if(dir == 0) //dir : L->R
        {
          dir = 1;
          i++; j--; steps--; //STEPS REDUCTION
        }
        else if(dir == 1) //dir : U->D
        {
          dir = 2;
          i--; j--;
        }
        else if(dir == 2) //dir : R->L
        {
          dir = 3;
          i--; j++; steps--;//STEPS REDUCTION
        }
        else if(dir == 3) //dir : D->U
        {
          dir = 0;
          i++; j++;
        }
        else
        {
          std::cout << "BAD CODE" << '\n';
          // return -2;
        }

    }//end of OUTER while loop
    return ans;
}


/*
CONCISE SOLUTION :

#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>>& arr)
{
  std::vector<int> v;
  if(arr[0].empty()) return v;
  int i=0,k=0,x=arr.size(),y=0;
  while(x>0)
  {
    for(; k <x; ++k) v.push_back(arr[i][k]); ++i; --k;
    for(; i <x; ++i) v.push_back(arr[i][k]); --i; --k;
    for(; k>=y; --k) v.push_back(arr[i][k]); --i; ++k; ++y;
    for(; i>=y; --i) v.push_back(arr[i][k]); ++i; ++k; --x;
  }
  return v;
}
*/
