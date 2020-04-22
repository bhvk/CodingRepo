// https://www.codewars.com/kata/55c4eb777e07c13528000021/
//FIND NUMBER OF ZEROES IN FACTORIAL OF NUMBER IN BASE B

// CPP program to find the largest power of k that divides n! {where k may not be prime}

#include <vector>
#include <utility>
// To find the power of a prime p in factorial N
int findPowerOfP(int n, int p)
{
	int count = 0;
	int r=p;
	while (r <= n)
  {
		// calculating floor(n/r) and adding to the count
		count += (n / r);
		// increasing the power of p from 1 to 2 to 3 and so on
		r = r * p;
	}
	return count;
}

// returns all the prime factors of k
std::vector<std::pair<int, int>> primeFactorsofK(int k)
{
	// std::vector to store all the prime factors along with their number of occurrence in factorization of k
	std::vector<std::pair<int, int>> ans;
  int count = 0;
  if(k%2==0)
  {
    while(k%2 == 0)
    {
      count++;
      k = k/2;
    }
    ans.push_back(std::make_pair(2, count));
  }
  //now k is odd
	for(int i=3; i*i<=k; i+=2)// for (int i = 2; k != 1; i++)
  {
		if (k % i == 0)
    {
			int count = 0;
			while (k % i == 0)
      {
				k = k / i;
				count++;
			}
			ans.push_back(std::make_pair(i, count));
		}
	}
  if(k>2)
    ans.push_back(std::make_pair(k, 1));

	return ans;
}

// Returns largest power of k that divides n!
int Zeroes(int base, int number)
{
	std::vector<std::pair<int, int>> vec;
	vec = primeFactorsofK(base);
	int ans = INT_MAX;
	for (int i = 0; i < vec.size(); i++)
  {
    // calculating minimum power of all the prime factors of k
		ans = std::min(ans, findPowerOfP(number, vec[i].first) / vec[i].second);
  }
	return ans;
}

// Driver code
// int main()
// {
// 	//cout << largestPowerOfK(7, 2) << endl;
// 	cout << largestPowerOfK(3929, 22) << endl;
// 	return 0;
// }
