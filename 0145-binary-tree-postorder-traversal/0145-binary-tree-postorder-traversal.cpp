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
void postdisplay(TreeNode* root,vector<int> &ans)
{
    stack<TreeNode*> st;

    if(root!=NULL) st.push(root);

    while(st.size()>0)
    {
        TreeNode* x=st.top();
        st.pop();
        ans.push_back(x->val);
        // revrse check krenge kunki it acts as reverse
        if(x->left!=NULL) st.push(x->left);
        if(x->right!=NULL) st.push(x->right);
    }
    reverse(ans.begin(),ans.end());
}
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        postdisplay(root,ans);
        return ans;
    }
};