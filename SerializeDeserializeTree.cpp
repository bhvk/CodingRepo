/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//CLEAN CODE
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if(!root)
            return "#";
        return to_string(root->val)+","+ serialize(root->left)+","+serialize(root->right);
    }
    TreeNode* deserialize(string data)
    {
        int pos=0;
        return deserializeUtil(data, pos);
    }
    TreeNode* deserializeUtil(string &data, int &pos)
    {
        // data[pos] == "#" compares adderesses; use '#' or use strcmp instead
        if(pos < data.length() && data[pos] == '#')
        {
            pos += 2; //due to skipping of # and ,
            return nullptr;
        }

        int delimiterPos = data.find(",",pos);
        int lenOfNum = delimiterPos-pos;
        int value = stoi(data.substr(pos, lenOfNum));
        TreeNode* root = new TreeNode(value);
        pos = delimiterPos+1;

        root->left = deserializeUtil(data, pos);
        root->right = deserializeUtil(data, pos);

        return root;
    }
};






#if 0

//did all this jugglery in serialize because did not read
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if(!root)
            return "[]";

        vector<string> v;
        queue<TreeNode*> q;
        // BFS()
        q.push(root);
        v.push_back(to_string(root->val));
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            // v.push_back(to_string(curr->val));
            if(!curr->left)
                v.push_back("#");
                // v.push_back("null");
            if(!curr->right)
                v.push_back("#");
            if(curr->left)
            {
                v.push_back(to_string(curr->left->val));
                q.push(curr->left);
            }
            if(curr->right)
            {
                v.push_back(to_string(curr->right->val));
                q.push(curr->right);
            }

            q.pop();
        }
        for(auto k : v)
            cout<<k<<", ";
        cout<<"\n";

        int i = v.size()-1;
        while(v[i] == "#")
            i--;

        string str1 = "[";
        for(int x=0; x<=i; x++){
            str1 += v[x]+",";

        }
        string ans = str1.substr (0,str1.length()-1); //to remove last comma
        ans = ans+"]";

        cout<<"ANSWER : "<<ans<<"\n";

        return ans;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        return nullptr;
        cout<<"Original data : "<<data<<"\n";

        string s = data.substr (1,data.length()-2);
        int n = s.size();
        // cout<<"DATA : "<<s<<"\n";
        queue<string> q;
        // vector<string> vect;

        /******************************************/
        stringstream ss(s);
        // deque<string>::iterator it = q.begin();
        while (ss.good())
        {
            string substr;
            getline(ss, substr, ',');
            q.push(substr);
            // vect.push_back(substr);
        }
        /******************************************/

        // cout<<"TOKENS : "<<"\n";
        // for (auto k : vect)
        //     cout << k <<", ";
        // cout<<"\n";
        //CONSTRUCT TREE
//         TreeNode* head = new TreeNode(q.front());
//         while(!q.empty())
//         {
//             TreeNode* curr = new TreeNode(stoi(q.front()));

//         }
        // TreeNode* start = new TreeNode(stoi(q.front()));
        // TreeNode* head = makeTree(q, start);
        // // return nullptr;
        // return head;
    }
//     TreeNode* makeTree(queue<string> q, TreeNode* start)
//     {
//         if(!root)
//             return nullptr;

//         TreeNode* root = start;
//         q.pop();
//         root->left = makeTree(q, root->left)
//     }
};
#endif
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
