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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        // we will be doing it using breadth first serach 
        queue<TreeNode*>q;
        vector<vector<int>>fans;
        if(root!=NULL) q.push(root);
        while(q.size()>0)
        {
            vector<int>ans;
            int n=q.size();

            for(int i=0;i<n;i++)
            {
                TreeNode* x=q.front();
                q.pop();
                ans.push_back(x->val);
                if(x->left!=NULL) q.push(x->left);
                if(x->right!=NULL)q.push(x->right);
            }
            fans.push_back(ans);
        }
        return fans;
    }
};