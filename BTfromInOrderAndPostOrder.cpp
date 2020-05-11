//Construct Binary tree from give PostOrder and InOrder traversal

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int postIndex = postorder.size()-1;
        if(inorder.empty())
            return nullptr;

        return bTU(inorder, 0, inorder.size()-1, postorder, &postIndex);
    }
    //Utility Function
    TreeNode* bTU(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int* postIndex)
    {
        if(inStart>inEnd)
            return nullptr;
        //in C++ we use new keyword else we were getting alloc-dealloc weird error
        /*https://leetcode.com/problems/add-two-numbers/discuss/316730/this-code-gives-malloc-delete-mismatch-why-should-i-dealloc-memory*/
        TreeNode* node = new TreeNode(postorder[*postIndex]);

        int inIndex = searchFor(inorder, inStart, inEnd, postorder[*postIndex]);
        (*postIndex)--;

        if(inStart == inEnd)
            return node;

        // int inIndex = searchFor(inorder, inStart, inEnd, postorder[*postIndex]); //not to be placed here
        cout<< "In-order Index is : "<< inIndex<<"\n";
        node->right = bTU(inorder, inIndex+1, inEnd, postorder, postIndex); //1.
        node->left = bTU(inorder, inStart, inIndex-1, postorder, postIndex);//2. //ORDER MATTERS

        return node;

    }
    int searchFor(vector<int>& inorder, int inStart, int inEnd, int val){
        int i;
        for(i =inStart; i<=inEnd; i++){
            if(inorder[i] == val)
                break;
        }
        return i;
    }
};
