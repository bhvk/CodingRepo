//https://leetcode.com/problems/maximum-sum-circular-subarray/
//MAX_SUM_SUBARRAY (circular)

//Kadane with a twist:
//max_sum is either max contigious sum
//or (total - min_contiguos_sum) [i.e. if max sum  lies at start and end,] middle part would be min
// total_sum = arr[start,i] + arr[i+1,j] + arr[j+1, end];

//if arr[i+1,j] is LEAST then arr[start,i]+arr[j+1, end] is max {CASE when max subarray is cyclic}

class Solution
{
public:
    int maxSubarraySumCircular(vector<int>& A)
    {
        //Kadane
        int max_ans = -30001; int maxSoFar = 0;
        int min_ans = 30001; int minSoFar = 0;
        int sz = 0;
        int total = 0;
        for(int i=0; i<A.size(); i++)
        {
            maxSoFar = max(A[i], maxSoFar+A[i]);
            minSoFar = min(A[i], minSoFar+A[i]);

            max_ans = max(max_ans, maxSoFar);
            min_ans = min(min_ans, minSoFar);

            total +=A[i];
        }

        if(total-min_ans == 0) // implies all negative **IMPORTANT**
            return max_ans;

        return max(total-min_ans, max_ans);
    }
};

/*
cout<<"total : "<<total<<"\n";
cout<<"min_ans : "<<min_ans<<"\n";
cout<<"total-min_ans: "<<total-min_ans<<"\n";
cout<<"max_ans : "<<max_ans<<"\n";
cout<<"ANSWER : "<<max(total-min_ans, max_ans)<<"\n\n";
*/
