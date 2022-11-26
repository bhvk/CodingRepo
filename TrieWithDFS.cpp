#include <iostream>
using namespace std;

//MODIFIED THIS -> https://leetcode.com/problems/word-search-ii/solutions/2780127/c-trie-dfs-backtracking-faster-easy-to-understand/

int R, C;
int row[4] = {0,1,0,-1};
int col[4] = {1,0,-1,0};

class Trie
{
	public:
    Trie* children[26];
    bool endOfWord;
    string word;
    
    Trie()
    {
        word = "";
        endOfWord = false;
        for (int i = 0; i < 26; ++i)
        	children[i] = nullptr;
    }

    void insert(string &s)
    {
        Trie* currNode = this;
        for(char &c : s)
        {
            if(!currNode->children[c-'a'])
                currNode->children[c-'a'] = new Trie();
            currNode = currNode->children[c-'a'];
        }
        currNode->endOfWord = true;
        currNode->word = s;
    }
};

class Solution 
{
public:
	void DFS(vector<vector<char>>& g, int i, int j, vector<string>& res, Trie* trie)
    {
        // if(i < 0 or i>= R or j<0 or j>=C or g[i][j] == '*') return;
        if(i < 0 or i>= R or j<0 or j>=C or g[i][j] == '*' || !trie->children[g[i][j]-'a']) return;
		
        char c = g[i][j];
		g[i][j] = '*';

		// Trie *t = trie->children[c-'a'];
        trie = trie->children[c-'a'];
        if(trie->endOfWord)
        {
            res.push_back(trie->word);
            trie->endOfWord = false; // mark is_end with false to avoid duplicate result
        }
            
        for(int k=0; k<4; ++k)
            DFS(g, i+row[k], j+col[k], res, trie);

        g[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& g, vector<string>& words) 
    {
        //dimensions of given board (grid)
        R = g.size();
        C = g[0].size();
        vector<string> res;
        //insert all dictionary in trie
        // Trie* t = new Trie();
        Trie trie;
        for(string &w : words)
        {
            trie.insert(w);
            trie.word = w;
        }
            
        for(int i=0; i<R; ++i)
            for(int j=0; j<C; ++j)
        		DFS(g, i, j, res, &trie);

        return res;
    }
};