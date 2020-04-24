//https://www.codewars.com/kata/52b7ed099cdc285c300001cd/

#include <vector>
#include <utility>

int sum_intervals(std::vector<std::pair<int, int>> intervals)
{
  //sort intervals on basis of pair.first
  std::sort(intervals.begin(), intervals.end());

  for(auto &k : intervals)
    std::cout << k.first <<", "<<k.second;
  std::cout<<"\n";

  int A   = intervals[0].first;
  int B   = intervals[0].second;
  int sum = B-A;

  for(size_t i=1; i< intervals.size(); i++)
  {
    int C = intervals[i].first;
    int D = intervals[i].second;

    if(A<=C && B>=D) //if(A<=C && B>=C && B>=D)
      continue;
      // sum += (B-A);

    else if(A<=C && B>=C && B<D) //else if(A<=C && B>C && B<=D)
    {
      sum = (sum-(B-A))+(D-A);
      B = D;
    }
    else if(B<C) //else if(A<C && B<C)
    {
      sum += (D-C);
      A = C;
      B = D;
    }
  }

  return sum;
}
