/*
Rick is a fan of logic-based games. However, he is bored of the classic ones, like Sudoku and Mastermind, since he has solved many of them. Recently he found a new game in which one is given a string with some question markes in it. The objective is to replace all of the question marks with letters(one letter per question mark) in such a way that no letter appears next to another letter of the same kind.

Write a function that given a string riddle, returns a copy of the string with all of the question marks replaced by lowercase letters(a-z) in such a way that the same letters do not occur next to each other. The result can be any of the possible answers as long as it fulfils the above requirements.

Examples:

Given riddle = "ab?ac?" , your function might return "abcaca". Some other possbile results are "abzacd", "abfacf".
Given riddle = "rd?e?wg??", your function might return "rdveawgab".
Given riddle = "????????, your function might return "codility".

*/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#define PRINT
string solution(string &s) 
{
    // write your code in C++14 (g++ 6.2.0)
    int n = s.size();
    // cout<<"len = "<<n<<endl;
    if(n== 1 && s[0]=='?')
        return "a";
    if(s.length() == 1)
        return s;
        
    vector<char>al = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
#ifdef PRINT    
    cout<<"Al size = "<<al.size()<<endl
#endif    
    int x=0;
    string ans="";

    if(s[0] == '?')
    {
        if(s[1] == al[x])
            x++;
        ans += al[x%26];
        x++;
    }
    else
        ans += s[0];
    for(int i=1; i<(int)s.length()-1; ++i)
    {
        if(s[i] == '?')
        {
            while(s[i-1] == al[x%26] or s[i+1] == al[x%26])
                x++;
            ans += al[x%26];
            x++;
        }
        else
            ans += s[i];
    }
    if(s[n-1] == '?')
    {
        if(s[n-2] == al[x%26])
            x++;
        x = x%26;
        ans += al[x%26];
    }
    else
        ans += s[n-1];
    return ans;
}



/*
"??yw?ipkd?"
"?xp???e??dy?"
"?????????????????????????????"
*/

/*MY BETTER SOLN USING RAND()*/
string modifyString(string s) 
{
    string ans = "";
    srand(time(NULL));
    for(int i=0; i<s.length(); ++i)
    {
        if(s[i] == '?')
        {
            int randNum = rand()%26;
            int prev = i-1 >= 0 ? s[i-1]-'a' : 27;
            int next = (i+1 < s.length() and s[i+1] != '?' ) ? s[i+1] -'a' : 27; 
            while(randNum == prev or randNum == next)
                randNum = rand()%26;
            s[i] = randNum + 'a';
        }
    }
    return s;
}