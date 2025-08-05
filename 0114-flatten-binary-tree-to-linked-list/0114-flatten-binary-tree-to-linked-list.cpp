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
    void preorder(TreeNode* root, vector<TreeNode*>& ans)
    {
        if (root == nullptr) return;

        ans.push_back(root);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    void flatten(TreeNode* root) 
    {
        vector<TreeNode*> ans; // Vector to store preorder traversal
        preorder(root, ans);
         if (ans.size() == 0) return;
        // Now link all nodes to form a flattened list
        for (int i = 0; i < ans.size() - 1; i++) {
            ans[i]->left = nullptr;
            ans[i]->right = ans[i + 1];
        }
    }
};
