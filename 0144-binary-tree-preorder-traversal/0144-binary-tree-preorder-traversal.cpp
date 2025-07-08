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
   void predisplay(TreeNode* root,vector<int> &ans)
{
    stack<TreeNode*> st;

    if(root!=NULL) st.push(root);

    while(st.size()>0)
    {
        TreeNode* x=st.top();
        st.pop();
        ans.push_back(x->val);
        // revrse check krenge kunki stack ke top men we want left node upr rhe.
        if(x->right!=NULL) st.push(x->right);
        if(x->left!=NULL) st.push(x->left);
    }
}
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        predisplay(root,ans);
        return ans;
    }
};