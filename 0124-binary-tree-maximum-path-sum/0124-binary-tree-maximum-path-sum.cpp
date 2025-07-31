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
int maxsum=0;
 int dfs(TreeNode *root)
 {
    if(root==NULL) return 0;

    int leftpath=dfs(root->left);
    int rightpath=dfs(root->right);

    int neche_hi_milgya_ans=leftpath+rightpath+root->val;
    int koi_ek_accha= max(leftpath,rightpath) + root->val;
    int only_root_accha = root->val;

    maxsum=max({maxsum,neche_hi_milgya_ans,koi_ek_accha,only_root_accha} );

    // return ab 2nd and 3rd condition wale hi hinge
    return max(koi_ek_accha,only_root_accha );
 }
    int maxPathSum(TreeNode* root) 
    {
         
        maxsum=INT_MIN;
        dfs(root);
        return maxsum;
    }
};