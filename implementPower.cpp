//Implementing pow(x,n) = x^n;
//Fast Exponentiation (Exponentiation by squaring)

class Solution
{
public:
    double myPow(double x, int n)
    {
      if(n == INT_MIN)
        return (myPow(1/x, -(n+1))/x);
      if(n<0)
        return myPow(1/x, -n);

      if(n==0)
        return 1;

      double ans = 1;
      while(n>1)
      {
        if(n%2 == 0)
        {
          x *= x;
          n /= 2;
        }
        else
        {
          ans *=x;
          x *= x;
          n = (n-1)/2;
        }
      }
      return ans;
    }
};
/*

SMALL SOLUTION

class Solution {
public:
    double myPow(double x, int n) {
        if (n == std::numeric_limits<int>::lowest()) {
            return myPow(1 / x, -(n + 1)) / x;
        }
        if (n < 0) {
            return myPow(1 / x, -n);
        }
    	double ans = 1;
		while (n) {
			if (n & 1 == 1) ans *= x;
			x *= x;
			n >>= 1;
		}
		return ans;
    }
};
*/
