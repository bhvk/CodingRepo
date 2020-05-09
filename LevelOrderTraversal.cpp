//BFS Level-Order traversal

// ************** 2-Queue Solution ******************
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        queue<TreeNode*> qA;
        queue<TreeNode*> qB;
        qA.push(root);
        vector<int> t_ans;
        while(!qA.empty() || !qB.empty())
        {
            while(!qA.empty())
            {
                TreeNode* currA = qA.front();
                qA.pop();
                t_ans.push_back(currA->val);
                if(currA->left)
                    qB.push(currA->left);
                if(currA->right)
                    qB.push(currA->right);
            }
            ans.push_back(t_ans);
            t_ans.clear();
            while(!qB.empty())
            {
                TreeNode* currB = qB.front();
                qB.pop();
                t_ans.push_back(currB->val);
                if(currB->left)
                    qA.push(currB->left);
                if(currB->right)
                    qA.push(currB->right);
            }
            if(!t_ans.empty())
                ans.push_back(t_ans);
            t_ans.clear();
        }
        return ans;
    }
};





//*********** Concise 2-Queue Solution *********************
//************* 1-Queue Solution ***************************
vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> res;
    queue<TreeNode*> q;
    vector<int> level;
    if(root != NULL)
    {
        q.push(root);
        level.push_back(root->val);
        res.push_back(level);
        level.clear();

        while(!q.empty())
        {
            int i, n;
            n = q.size();
            for(i = 0; i < n; i++)
            {
                TreeNode* p = q.front();
                q.pop();

                if(p -> left != NULL)
                {
                    q.push(p->left);
                    level.push_back(p->left->val);
                }
                if(p-> right != NULL)
                {
                    q.push(p->right);
                    level.push_back(p->right->val);
                }
            }
            if(!level.empty() && i == n)
            {
                res.push_back(level);
                level.clear();
            }
        }
    }
     return res;
}
