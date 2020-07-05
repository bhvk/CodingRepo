//EASY TO UNDERSTAND O(N^3) solution: from https://www.youtube.com/watch?v=8HYXkNB39KA
class Solution {
public:
	/*
	arr[][] = {{1, 0, 1, 1},
               {0, 1, 0, 1},
               {1, 1, 1, 0},
               {1, 0, 1, 1}}
p_arr[][] -> store 0 if arr[i][j] = 0 else cumulative number of consecutive 1s on right at [i][j] for
for above will look like
              {{1, 0, 2, 1},
               {0, 1, 0, 1},
               {3, 2, 1, 0},
               {1, 0, 2, 1}}
	*/
    void findPrefixCount(vector<vector<int>>& p_arr, vector<vector<int>>& arr, int& m, int& n)
	{
		for (int i = 0; i < m; i++)
		{
			int c = 0;
			for (int j = n - 1; j >= 0; j--)
			{
				c = arr[i][j] ? c+1 : 0;
				p_arr[i][j] = c;
			}
		}
	}

	int numSubmat(vector<vector<int>>& arr)
	{
		int m = arr.size();
		int n = arr[0].size();
		vector<vector<int>> p_arr(m, vector<int>(n, 0));

		findPrefixCount(p_arr, arr, m, n);

		// variable to store the final answer
		int ans = 0;

		/* fixing top-left cell and count matrices from there-on */
		for (int i = 0; i < m; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				int x = INT_MAX;
				for(int k=i; k < m; ++k)
				{
					x = min(x, p_arr[k][j]);
					ans+=x;
				}
			}
		}
		return ans;
	}
};

//---------------------------------------------------------------------------------------------------------------------

//O(N^2) Solution:
class Solution {
public:
	/*
	arr[][] = {{1, 0, 1, 1},
               {0, 1, 0, 1},
               {1, 1, 1, 0},
               {1, 0, 1, 1}}
p_arr[][] -> store 0 if arr[i][j] = 0 else cumulative number of consecutive 1s on right at [i][j] for
for above will look like
              {{1, 0, 2, 1},
               {0, 1, 0, 1},
               {3, 2, 1, 0},
               {1, 0, 2, 1}}
	*/
    void findPrefixCount(vector<vector<int>>& p_arr, vector<vector<int>>& arr, int& m, int& n)
	{
		for (int i = 0; i < m; i++)
		{
			int c = 0;
			for (int j = n - 1; j >= 0; j--)
			{
				if (arr[i][j])
                    ++c;
                else
					c=0;

				p_arr[i][j] = c;
			}
		}
	}

	int numSubmat(vector<vector<int>>& arr)
	{
		int m = arr.size();
		int n = arr[0].size();
		vector<vector<int>> p_arr(m, vector<int>(n, 0));

		findPrefixCount(p_arr, arr, m, n);

		// variable to store the final answer
		int ans = 0;

		/* Loop to evaluate each column of the prefix matrix uniquely.
		For each index of a column we will try to determine the number of sub-matrices starting from that index and has all 1s */
		for (int j = 0; j < n; j++) {
			int i = m - 1;

			/* Stack to store elements and the count of the numbers they popped

				First part of pair will be the value of inserted element.
				Second part will be the count of the number of elements pushed before with a greater value */
			stack<pair<int, int> > q;

			// variable to store the number of submatrices with all 1s
			int to_sum = 0;

			while (i >= 0)
			{
				int c = 0;
				while (q.size() != 0 && q.top().first > p_arr[i][j])
				{
					to_sum -= (q.top().second + 1) * (q.top().first - p_arr[i][j]);
					c += q.top().second + 1;
					q.pop();
				}
				to_sum += p_arr[i][j];
				ans += to_sum;
				q.push({ p_arr[i][j], c });
				i--;
			}
		}
		return ans;
	}
};
