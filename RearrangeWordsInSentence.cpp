class Solution
{
public:
    string arrangeWords(string text)
    {
        if(text.size() ==0)
            return "";


        text[0] = tolower(text[0]);

        // vector<pair<string, int>> v;
        vector<string> v;

        stringstream ss(text);
        // int ind = 0;

        while (ss.good())
        {
            string substr;
            getline(ss, substr, ' ');
            v.push_back(substr);
            // v.push_back({substr, ind});
            // ind++;
        }

        ss.str(""); //clear stringstream

        //stable_sort(v.begin(), v.end(), []

        // sort(v.begin(), v.end(), []
        // (const pair<string,int> &s1, const pair<string,int> &s2){
        //     if(s1.first.size() == s2.first.size())
        //         return s1.second < s2.second;
        //     else
        //         return s1.first.size() < s2.first.size();
        // });


        stable_sort(v.begin(), v.end(), []
        (const string &s1, const string &s2){
                return s1.size() < s2.size();
        });
        string ans="";

        for(auto k : v)
            ans += k+' ';
            // ans += k.first+' ';

        ans[0] = toupper(ans[0]);

        return ans.substr(0,ans.size()-1); //or first ans.pop_back();
    }

};

//Input
// "Jlhvvd wfwnphmxoa qcuucx qsvqskq cqwfypww dyphntfz hkbwx xmwohi qvzegb ubogo sbdfmnyeim tuqppyipb llwzeug hrsaebveez aszqnvruhr xqpqd ipwbapd mlghuuwvec xpefyglstj dkvhhgecd kry"

//output
//"Kry hkbwx ubogo xqpqd jlhvvd qcuucx xmwohi qvzegb qsvqskq llwzeug ipwbapd cqwfypww dyphntfz tuqppyipb dkvhhgecd wfwnphmxoa sbdfmnyeim hrsaebveez aszqnvruhr mlghuuwvec xpefyglstj"
