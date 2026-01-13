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
bool check(TreeNode* leftNode, TreeNode* rightNode) 
{
// If both nodes are NULL, they are symmetric
    if (leftNode == NULL && rightNode == NULL)
        return true;
    // If only one of them is NULL, they are not symmetric
    if (leftNode == NULL || rightNode == NULL)
        return false;
    // If values are different, they are not symmetric
    if (leftNode->val != rightNode->val)
        return false;
    // Recursively check symmetry
    bool leftside=check(leftNode->left, rightNode->right);
    bool rightside=check(leftNode->right, rightNode->left);
    return leftside && rightside;
}

bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL) return true;
        
        return check(root->left,root->right);
        
    }
};