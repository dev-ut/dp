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
        // we will write The bfs code 
        queue<TreeNode*>q;
        if(root!=NULL)q.push(root);
        vector<vector<int>>fans;
        while(q.size()>0)
        {
            int n=q.size();
            vector<int>ans;
            for(int i=0;i<n;i++)
            {
                TreeNode*x=q.front();
                q.pop();
                ans.push_back(x->val);
                //we will ask that agr left child hai to daalo and agr right child hai to daalo 
                if(x->left!=NULL) q.push(x->left);
                if(x->right!=NULL) q.push(x->right);
            }
            // jaise ye looop khtm hoga ie we have traversed 1 level 
            fans.push_back(ans);
        }
        return fans;
    }
};