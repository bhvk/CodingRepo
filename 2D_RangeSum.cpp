#include <bits/stdc++.h>
using namespace std;

vector<long long> rectangularSquare(int n, vector<vector<int>> mat, int q, vector<vector<int>> qry)
{
     // Write your code here
    vector<long long> ans;
    vector<vector<int>> aux(n, vector<int>(n, 0));

    //preprocess
    for (int i=0; i<n; i++)
      aux[0][i] = mat[0][i];
    // Do column wise sum
   for (int i=1; i<n; i++)
      for (int j=0; j<n; j++)
         aux[i][j] = mat[i][j] + aux[i-1][j];

    // Do row wise sum
   for (int i=0; i<n; i++)
      for (int j=1; j<n; j++)
         aux[i][j] += aux[i][j-1];

    for(auto v : qry)
    {
        int x = v[0];
        int y = v[1];
        int l = v[2];
        int b = v[3];
        int tli = max(0, x-l);
        int tlj = max(0, y-b);
        int rbi = min(n-1, x+l);
        int rbj = min(n-1, y+b);
        cout<<"tli :"<<tli<<", tlj : "<<tlj<<endl;
        cout<<"rbi :"<<rbi<<", rbj : "<<rbj<<endl;
        /*
        tli :  Row number of top left of query submatrix
        tlj :  Column number of top left of query submatrix
        rbi :  Row number of bottom right of query submatrix
        rbj :  Column number of bottom right of query submatrix
        */
       // result is now sum of elements between (0, 0) and  (rbi, rbj)
        long long res = aux[rbi][rbj];

        // Remove elements between (0, 0) and (tli-1, rbj)
        if (tli > 0)
           res = res - aux[tli-1][rbj];

        // Remove elements between (0, 0) and (rbi, tlj-1)
        if (tlj > 0)
           res = res - aux[rbi][tlj-1];

        // Add aux[tli-1][tlj-1] as elements between (0, 0) and (tli-1, tlj-1) are subtracted twice
        if (tli > 0 && tlj > 0)
           res = res + aux[tli-1][tlj-1];

        ans.push_back(res);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> mat(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val;
            cin >> val;

            mat[i].push_back(val);
        }
    }

    int q;
    cin >> q;

    vector<vector<int>> query;

    for (int i = 0; i < q; i++)
    {
        int x, y, l, b;
        cin >> x >> y >> l >> b;

        query.push_back({x, y, l, b});
    }

    vector<long long> ans = rectangularSquare(n, mat, q, query);

    for (auto i : ans)
    {
        cout << i << endl;
    }
}

/*
7
1 2 3 4 5 6 7
8 9 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28
29 30 31 32 33 34 35
36 37 38 39 40 41 42
43 44 45 46 47 48 49
2
4 3 1 2
0 0 1 2


*/
