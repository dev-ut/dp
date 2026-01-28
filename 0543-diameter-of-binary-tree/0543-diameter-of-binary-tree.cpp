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
int mxdia=0;
int height(TreeNode * root)
{
    if(root==NULL) return 0;
    return 1+ max(height(root->left),height(root->right));
}
    int diameterOfBinaryTree(TreeNode* root) 
    {
          if(root==NULL) return 0;
          int depth=height(root->left)+height(root->right);
          // whatsoever ans cam ewe gona store it in mxdia 
          mxdia=max(mxdia,depth);

          // now we have to make call for every node so apply recurrsion 
          diameterOfBinaryTree(root->left);
          diameterOfBinaryTree(root->right);

          return mxdia;

    }
};