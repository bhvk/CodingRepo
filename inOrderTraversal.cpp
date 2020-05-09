//https://zhang-xiao-mu.blog/2019/07/20/tree-traversal-in-order-level-order/

/*
Pattern will be we first search the left branch of the tree and push all the left nodes to the stack.
When we reach the nullptr, we pop the last element and put it in our result.
Then we examine the right tree using the same pattern here.
*/

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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        if(!root)
            return ans;

        stack<TreeNode*> s;
        TreeNode* curr = root;

        while(!s.empty() || curr)
        {
            if(curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = s.top();
                ans.push_back(curr->val);
                s.pop();
                curr = curr->right;
            }
        }
        return ans;
    }
};
