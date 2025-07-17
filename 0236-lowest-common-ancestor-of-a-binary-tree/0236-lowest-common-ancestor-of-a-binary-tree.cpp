/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
TreeNode* solveLCA(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    // Base condition check: agar root null hai ya fir root kisi node se match krta hai
    if (root == NULL)return NULL;

    if(root->val==p->val || root->val==q->val) 
    {
        return root;
    }

    
    TreeNode* leftSide = solveLCA(root->left, p, q);
    TreeNode* rightSide = solveLCA(root->right, p, q);

    // Result ko check karo aur conditions follow karo
    if (leftSide == NULL) return rightSide;
    else if (rightSide == NULL) return leftSide;
    else return root;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return solveLCA(root,p,q);
    }
};