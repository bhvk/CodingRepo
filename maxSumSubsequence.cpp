//https://www.codewars.com/kata/54521e9ec8e60bc4de000d6c/train/cpp
/*
The maximum sum subarray problem consists in finding the maximum sum of a
contiguous subsequence in an array or list of integers:
*/


/********************KADANE's ALGORITHM************************************/
#include <vector>
#include <algorithm>
using namespace std;

int maxSequence(const vector<int>& arr)
{
    int maxCurrent = arr[0], maxGlobal = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
    {
      maxCurrent = std::max(arr[i], arr[i]+maxCurrent);
      if(maxGlobal < maxCurrent)
        maxGlobal = maxCurrent;
    }
    return maxGlobal;
}
