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
// class Solution
// {
// public:
//     vector<int> preorderTraversal(TreeNode* root)
//     {
//         vector<int> ans;
//         preOrderTravUtil(root, ans);
//         return ans;
//     }
//     void preOrderTravUtil(TreeNode* root, vector<int>& ans)
//     {
//         if(!root)
//             return;
//         ans.push_back(root->val);
//         preOrderTravUtil(root->left, ans);
//         preOrderTravUtil(root->right, ans);
//     }

// };

//***************** ITERATIVE SOLUTION *****************\\

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        if(!root)
            return ans;

        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty())
        {
            TreeNode* root = s.top();
            s.pop();
            ans.push_back(root->val);
            if(root->right)
                s.push(root->right);
            if(root->left)
                s.push(root->left);
        }
        return ans;
    }
};
