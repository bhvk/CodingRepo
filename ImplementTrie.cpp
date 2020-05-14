// Implementing a simple Trie (only for small alphabets)
class Trie
{
    Trie* children[26]; //since only small alphabets in input. else use HashMap (UnorderMap) to store
    bool isEndOfWord;
public:
    /** Initialize your data structure here. */
    Trie()
    {
        isEndOfWord = false;
        for(int i=0; i<26; ++i)
            children[i] = nullptr;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie* curr = this;
        for(char c : word)
        {
            if(!curr->children[c-'a'])
                curr->children[c-'a'] = new Trie;
            curr = curr->children[c-'a'];
        }
        curr->isEndOfWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie* curr = this;
        for(char c : word)
        {
            curr = curr->children[c-'a'];
            if(!curr)
                return false;
        }
        if(curr->isEndOfWord)
            return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie* curr = this;
        for(char c : prefix)
        {
            curr = curr->children[c-'a'];
            if(!curr)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/* EXAMPLE
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
*/
