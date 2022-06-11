//LC  : https://leetcode.com/problems/cinema-seat-allocation/

/*
STATEMENT : 
*/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;
bool isVacant(int s, int e, vector<int>&row){
    for(int seat : row)
    {
        if(seat >= s and seat<= end) return false;
    }
    return true;
}
int maxNumFam(int n, vector<vector<int>> &reservedSeats)
{
    unordered_map<int, vector<int> rows;
    for(auto &seatLoc : reservedSeats)
    {
        if(seatLoc[1] == 1 or seatLoc[1] == 10)continue;
        rows[seatLoc[0]].push_back(seatLoc[1]);
    }

    int fams = (n-rows.size())*2; //initial fully empty rows where entirely 2 fams can be accomodated
    for(auto &row : rows)
    {
        if(isVacant(2,5, row.second) or isVacant(4,7, row.second) or isVacant(6,9, row.second))
            fams++;
    }
    return fams;
}
int solution(int N, string &S) {
    // write your code in C++14 (g++ 6.2.0)
    // vector<vector<int>> reservedSeats(N, vector<int>(10, 0));
    vector<vector<int>> reservedSeats;
    vector <string> tokens;
    stringstream F(S);
    string intermediate;
    while(getline(F, intermediate, ' '))
        tokens.push_back(intermediate);

#ifdef PRINT
    for(auto v : tokens)
    {
        cout<<v<<" ";
    }
#endif
    for(auto &t : tokens)    
    {
        int row = stoi(t.substr(0, t.length()-1));
        // row -= 1;
        char c = t[t.length()-1];
        int col = c > 'I' ? c-'A' : c-'A'+1;
#ifdef PRINT        
        cout<<"int Row = "<<row<<endl;
        cout<<"int Col = "<<col<<endl;
#endif        
        reservedSeats.push_back({row, col});
    }

    return maxNumFam(N, reservedSeats);

}

