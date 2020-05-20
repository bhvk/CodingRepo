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
class Solution
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        int ans = -1;
        int i = 0;
        inOrder(root, i, k, ans);
        return ans;
    }
    void inOrder(TreeNode* root, int &i, int k, int &ans)
    {
        if(root->left) inOrder(root->left, i, k, ans);

        ++i;
        if(i==k)
        {
            ans = root->val;
            return;
        }

        if(root->right) inOrder(root->right, i, k, ans);

        return;
    }
};
