//Leetcode : Cousin in binary tree

//TO-DO : isCousins(TreeNode* root, int A, int B)
//if(LevelA == LevelB) && if(A and B are not siblings) : return True

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
    bool isCousins(TreeNode* root, int x, int y)
    {
        int parentX=0; int parentY=0; int depth=0; int levelX = -1; int levelY = -1;
        pAndLevel(root, x, y, depth, parentX, parentY, levelX, levelY);
        return ((parentX != parentY) && (levelX == levelY));
    }
    void pAndLevel(TreeNode* root, int x, int y, int depth, int& pX, int& pY, int& lX, int& lY)
    {
        // if(root == null)
        if(!root)return;
        //for left
        if(root->left){
            if(root->left->val == x)
            {
                pX = root->val;
                lX = depth+1;
            }else if(root->left->val == y){
                pY = root->val;
                lY = depth+1;
            }
        }
        //for right
        if(root->right){
            if(root->right->val == x)
            {
                pX = root->val;
                lX = depth+1;
            }else if(root->right->val == y){
                pY = root->val;
                lY = depth+1;
            }
        }

        //else recurse for next depth (or say height)
        pAndLevel(root->left, x, y, depth+1, pX, pY, lX, lY);
        pAndLevel(root->right, x, y, depth+1, pX, pY, lX, lY);

    }
};


/*Better Solution


class Solution
{
public:
    int xdepth, ydepth;
    bool commparent = false;
    TreeNode* saveparentleft=NULL;
    TreeNode* saveparentright = NULL;
    void rectraversal(TreeNode* root,int x, int y , int depth, TreeNode* parent)
    {
        if(root == NULL)
            return;

        else
        {
            //cout << "rval " << root->val << endl;
            //cout << "depth " << depth << endl;
            depth++;
            if(root->val == x )
            {
                xdepth = depth;
                saveparentleft = parent;
            }
            if(root->val == y)
            {
                ydepth = depth;
                saveparentright = parent;
            }
            //depth = depth+1;
            rectraversal(root->left, x, y, depth, root);
            rectraversal(root->right, x, y, depth, root);
            return;
        }
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int depth=0;
        rectraversal(root, x, y, depth, root);
        cout << xdepth << ydepth << endl;
        cout << saveparentleft << saveparentright << endl;

        if(xdepth != ydepth)
            return false;
        else if(saveparentleft == saveparentright)
            return false;
        else
            return true;
    }
};
*/
