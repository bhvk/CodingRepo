class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        if(s1.length() > s2.length())
            return false;
        if(s1.length() == 0 && s2.length() > 0)
            return true;

        array<int,26> mapA{0};
        array<int,26> mapB{0};

        for(char c : s1) mapA[c - 'a']++;

        for(int i=0; i<s1.length(); ++i) mapB[s2[i]-'a']++;

        if(mapA == mapB)
            return true;

        //starting looping after first-window
        for(int i = s1.length(); i<s2.length(); ++i)
        {
            mapB[s2[i] - 'a']++; //moving sliding window by 1 step to right in array and including new element in window
            mapB[s2[i-s1.length()] - 'a']--; //removing first element in previous window (as a result of sliding window)

            if(mapA == mapB)
                return true;
        }

        return false;

    }
};
