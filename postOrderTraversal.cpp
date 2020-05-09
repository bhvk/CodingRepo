//https://zhang-xiao-mu.blog/2019/01/20/tree-traversal-preorder-postorder/

/*
The similar thing to preorder traversal.
The only thing we need change is the order of the sub tree traversal.
This time we start from left, then right and finally root.

Finally REVERSE the printed list
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        if(!root)
            return ans;

        stack<TreeNode*> s;
        TreeNode* curr = root;
        s.push(curr);
        while(!s.empty())
        {
            curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            if(curr->left)
                s.push(curr->left);
            if(curr->right)
                s.push(curr->right);
        }
        return reverse(ans.begin(),ans.end()); //IMPORTANT STEP
    }
};
