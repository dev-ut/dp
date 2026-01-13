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
bool check(TreeNode* leftnode,TreeNode* rightnode)
{
    if(leftnode==NULL && rightnode==NULL) return true;
    if(leftnode!=NULL && rightnode==NULL || leftnode==NULL && rightnode!=NULL) return false;
    if(leftnode->val!=rightnode->val) return false;

    bool outercheck=check(leftnode->left,rightnode->right);
    bool innercheck=check(leftnode->right,rightnode->left);
    if(outercheck==false) return false;
    if(innercheck==false) return false;

    return true;
}
    bool isSymmetric(TreeNode* root) 
    {
      if(root==NULL) return false;
       return check(root->left,root->right);    
    }
};