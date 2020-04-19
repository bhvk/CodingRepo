//Differernt solution: this code gives all numbers of len(observed) in NcR format
//where n = {1,2,3,4..whatever adjacent nos} and r is len(observed) in all permutations


https://www.geeksforgeeks.org/print-all-combinations-of-given-length/

#include <string>
#include <vector>
#include <set>
std::vector<std::string> g_ans;
int len;
void printAllKLengthRec(char set[], std::string prefix, int n, int k)
{
    // Base case: k is 0, print prefix
    if (k == 0)
    {
        // std::cout << (prefix) << std::endl;
        if(prefix.size() == len)
          g_ans.push_back(prefix);

        return;
    }
    // One by one add all characters from set and recursively call for k equals to k-1
    for (int i = 0; i < n; i++)
    {
        std::string newPrefix;
        // Next character of input added
        newPrefix = prefix + set[i];
        // k is decreased, because we have added a new character
        printAllKLengthRec(set, newPrefix, n, k - 1);
    }
}

void printAllKLength(char set[], int k, int n)
{
    printAllKLengthRec(set, "", n, k);
}
std::vector<std::string> get_pins(std::string observed)
{
  // std::vector<std::string> g_ans{};
  std::map<char, std::vector<int>> mapOfPins= {
    {'0', {0, 8}},{'1', {1,2,4}},{'2', {1,2,3,5}},{'3', {2,3,6}},
    {'4', {1,4,5,7}},{'5', {2,4,5,6,8}},{'6', {3,5,6,9}},{'7', {4,7,8}},
    {'8', {0,5,7,8,9}},{'9', {6,8,9}}
  };
  len = observed.length();
  int flag[10] ={}; int count =0;
  for(char& c : observed)
  {
    auto vec = mapOfPins[c];
    for(int i = 0; i<vec.size(); i++)
    {
      int x = vec[i];
      if(flag[x] == 0)
      {
        flag[x] = 1;
        count++;
      }
    }
  }
  char set[count];
  int x = 0;
  for(int i=0; i<10; i++)
  {
    if(flag[i] !=0)
    {

//       set[x] = static_cast<char>(i);
      set[x] = '0'+i;
      std::cout<< set[x] <<std::endl;
      x++;
    }
  }
  // ans =
  printAllKLength(set, len, count);
  return g_ans;
}
