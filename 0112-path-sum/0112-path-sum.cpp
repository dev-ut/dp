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
bool dfs(TreeNode* root, int targetSum)
{
    
   if(root==NULL) return false;

   // agr leaf node pr aagye to check simply ki wo tarfetsum ki jo updated value hai wo ane wali node ki value ke barabar hai ki nhi 

   if(root->left==NULL && root->right==NULL)
   {
    if(targetSum==root->val) return true;
    else return false;
   }

   

    bool leftpath=dfs(root->left,targetSum-root->val);
    bool rightpath= dfs(root->right,targetSum-root->val);

    return leftpath||rightpath;

}
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        return (dfs(root,targetSum));   

        
    }
};