/*Given two arrays of strings a1 and a2 return a sorted array r in lexicographical
order of the strings of a1 which are substrings of strings of a2. */
#include <algorithm>

class WhichAreIn
{
public:
    static std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2)
    {
        std::vector<std::string> results;

        std::copy_if( array1.begin( ), array1.end( ), std::back_inserter( results ),
        [&](const std::string &item1) {return std::any_of( array2.begin( ), array2.end( ),[&](const std::string &item2){return item2.find( item1 ) != std::string::npos;});}
                    );
        //^ lambda expression or C++ Functors
        //quick tutorial : https://medium.com/@winwardo/c-lambdas-arent-magic-part-1-b56df2d92ad2
        std::sort( results.begin( ), results.end( ) );

        return results;
    }
};


/*MY SOLUTION*/


class WhichAreIn
{

  public:
    static std::vector<std::string> inArray(std::vector<std::string> &arr1, std::vector<std::string> &arr2)
    {
      std::vector<std::string> ans;

      for(int i=0; i<arr1.size(); i++)
      {
        std::string s1 = arr1[i];
//         std::cout<< s1<<"\n";
        for(int j=0; j<arr2.size(); j++)
        {
          std::string s2 = arr2[j];
//           std::cout<<s2<<"\n";
//           bool b = boost::algorithm::contains(s2, s1);
//           if(b)
          if (s2.find(s1) != std::string::npos)
          {
            ans.push_back(arr1[i]);
          }
        }
      }

      // Sorting the array
      std::sort(ans.begin(), ans.end());

      // Using std::unique
      int l = ans.size();
      std::vector<std::string>::iterator ip;
      ip = std::unique(ans.begin(), ans.begin() + l);
      
      // Resizing the vector so as to remove the undefined terms
      ans.resize(std::distance(ans.begin(), ip));

      return ans;
    }
};
