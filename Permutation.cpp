https://www.codewars.com/kata/5254ca2719453dcc0b00027d/train/cpp


/************************QUICK ANSWER USING STL*********************************

#include <iostream>
#include <string>
#include <vector>

vector<string> permutations(string s)
{
  sort(s.begin(), s.end());
  std::vector<std::string> ans{};
  do{
    ans.push_back(s);
  }while(std::next_permutation(s.begin(), s.end()));
  return ans;
}
*******************************************************************************/

*******************************************************************************
//TUSHAR ROY ANSWER : https://www.youtube.com/watch?v=nYFd7VHKyWQ
*******************************************************************************

#include <iostream>
#include <string>
#include <vector>

vector<string> permutations(std::string s)
{
  std::vector<std::string> ans{};
  //PERMUTATION LOGIC
  permutationUtil(s, 0, s.length()-1, ans);
  // Sorting the array
  std::sort(ans.begin(), ans.end());

  // Using std::unique
  int l = ans.size();
  std::vector<std::string>::iterator dup;
  dup = std::unique(ans.begin(), ans.begin() + l);

  // Resizing the vector so as to remove the undefined terms
  ans.resize(std::distance(ans.begin(), dup));

  return ans;
}

std::vector<string> permutationUtil(std::string a, int l, int r, std::vector<string>& ans)
{
  // Base case
	if (l == r){
		ans.push_back(a);
    return;
  }
	else
	{
		// Permutations made
		for (int i = l; i <= r; i++)
		{
			// Swapping done
			swap(a[l], a[i]);
			// Recursion called
			permute(a, l+1, r);
			//backtrack
			swap(a[l], a[i]);
		}
	}
}


/*
//convert string to char array;
int n = s.length();
char arr[n];
// std::strcpy(arr, s.c_str());
for(int i=0; i<n; i++)
  arr[i] = s[i];
// size_t arr_size = sizeof(arr)/sizeof(*arr);
// std::sort(arr, arr+arr_size);
std::sort(std::begin(arr), std::end(arr));
*/
