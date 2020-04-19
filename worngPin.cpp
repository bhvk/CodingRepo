#include <string>
#include <vector>

std::vector<std::string> get_pins(std::string observed)
{
  std::vector<std::string> ans;

  std::map<char, std::vector<int>> mapOfPins= {
    {'0', {0, 8}},{'1', {1,2,4}},{'2', {1,2,3,5}},{'3', {2,3,6}},
    {'4', {1,4,5,7}},{'5', {2,4,5,6,8}},{'6', {3,5,6,9}},{'7', {4,7,8}},
    {'8', {0,5,7,8,9}},{'9', {6,8,9}}
  };

  for (size_t i = 0; i < observed.length(); i++)
  {
    char c = observed[i];
    // std::cout<< c << std::endl;
    auto lst = mapOfPins[c];
    std::string newStr = observed;
    for(auto it = lst.begin(); it!=lst.end(); it++)
    {
      newStr.replace(i, 1, (std::to_string(*it)));
      ans.push_back(newStr);
    }
  }
  return ans;
}
