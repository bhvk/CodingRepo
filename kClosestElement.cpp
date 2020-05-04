class Solution
{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        std::ios::sync_with_stdio(false);
        // untie in/out streams
        std::cin.tie(nullptr);
        int l = 0;
        int r = arr.size()-1;
        vector<int>ans;
        if(x <= arr[l])
        {
            for(int i=0; i<k; i++)
            {
                ans.push_back(arr[i]);
            }
            return ans;
        }
        if(x>=arr[r])
        {
            for(int i=r; i>(r-k); i--)
            {
                ans.insert(ans.begin(), arr[i]);
            }
            return ans;
        }
        bool flag = false;
        while(l<r)
        {
            int mid = l+(r-l)/2;
            if(arr[mid] == x)
                flag = true;

            if(arr[mid]<x)
                l = mid+1;
            else
                r = mid;
        }
        if(!flag) //if arr[mid] was actually equal to x then l is the least index of x
            l = l-1;
        cout<<"l=: "<<l<< "\n\n";
        int count = k;
        if(count != 1)
        {
            ans.push_back(arr[l]);
            count = --k;
        }
        int L = l-1;
        int R = l+1;
        cout<<"Index at: "<<l<< ", leftPtr: "<<L<<", rightPtr: "<<R<<", count: "<<count<<"\n\n";
        // return ans;
        int diffL;
        int diffR;
        while(count>0)
        {
            diffL = L>=0 ? x-arr[L] : INT_MAX;
            diffR = R<arr.size() ? arr[R]-x : INT_MAX;
            if(diffL<=diffR)
            {
                ans.insert(ans.begin(),arr[L]);
                L--;
                count--;
                cout<<"DONE 1"<<"\n";
            }
            else //(diffR<diffL || R<num.size())
            {
                ans.push_back(arr[R]);
                R++;
                count--;
                cout<<"DONE 2"<<"\n";
            }
        }
        return ans;
    }
};


/*Small effecient solution*/
/*
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int size = arr.size(), i = 0, j = size-1, mid;
        while(j-i > 1) {
            mid = (i+j)/2; // only use if value guaranteed to not overflow, otherwise do <lo + (hi-lo)/2>
            if(arr[mid] > x) j = mid;
            else i = mid;
        }
        int closest = abs(arr[i] - x) < abs(arr[j] - x) ? i : j, l = closest, r = closest+1, start = closest;

        for(int a = 0; a < k; ++a) {
            int lv = l >= 0 ? abs(arr[l]-x) : INT32_MAX, rv = r < size ? abs(arr[r]-x) : INT32_MAX;
            if(lv <= rv) start = l--;
            else ++r;
        }
        return vector<int>(arr.begin()+start, arr.begin()+start+k);
    }
};

auto gucciGang = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
*/


//SOLUTION 2: ELEGANT
/*
vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
    int left = 0, right=arr.size()-k;
    while(left < right)
    {
        int mid = left + (right-left)/2;
        if(arr[mid] + arr[mid+k] < 2*x)
          left = mid + 1;
        else
          right = mid;
    }
    return vector<int>(arr.begin()+left, arr.begin()+left+k);
}
*/
