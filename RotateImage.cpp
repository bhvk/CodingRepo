//Rotate Image (Done with extra memory {NOT in-place})
class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        vector<vector<int>> ans = rotateUtil(matrix);
        for(size_t i=0; i<ans.size(); i++)
            for(size_t j=0; j<ans.size(); j++)
                matrix[i][j] = ans[i][j];
    }
    vector<vector<int>> rotateUtil(vector<vector<int>> const &mat)
    {
        int k = mat.size();
        vector<vector<int>> arr(k, vector<int>(k, 1)); //intialize 2-D matrix of size k*k

        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                arr[i][j] = mat[k-1-j][i];

        return arr;
    }
};


//Rotate Image : In-place
//1. Transpose
//2. swap row-wise elements accross center (i.e Mirror image, mirror is at center column)


class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);

		//Transpose
        for(int i=0; i<matrix.size(); i++)
		{
            for(int j=0; j<matrix.size(); j++)
			{
                if(j>i)
                {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
			}
		}
		
        cout<<"Before Rotate : "<<"\n";
        for(auto k: matrix)
        {
            for(size_t i=0; i<k.size(); i++)
                cout<<k[i]<<", ";
            // can be written as : for(auto k: mat) for(auto i : k) print
            cout<<"\n";
        }
		//Mirror image
		for(int i=0; i<matrix.size(); i++)
		{
			for(int j=0; j < matrix.size()/2; j++)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[i][matrix.size()-1-j];
				matrix[i][matrix.size()-1-j] = temp;
			}
		}
        cout<<"\n After Rotate : "<<"\n";
        for(auto k: matrix)
        {
            for(size_t i=0; i<k.size(); i++)
                cout<<k[i]<<", ";
            // can be written as : for(auto k: mat) for(auto i : k) print
            cout<<"\n";
        }
    }

};
