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
// void preorder(TreeNode* root, vector<int>&ans)
// {
//   if(root==NULL)
//   {
//     return;
//   }
//     ans.push_back(root->val);
//     preorder(root->left,ans);
//     preorder(root->right,ans);
// }
//     vector<int> preorderTraversal(TreeNode* root) 
//     {
//      //recurrsive
//      vector<int>ans;
//      preorder(root,ans);
//      return ans;
        
//     }
 void preorder(TreeNode* root, vector<int>&ans)
 {
    stack<TreeNode*>st;
    if(root!=NULL)st.push(root);

    while(st.size()>0)
    {
        TreeNode* x=st.top();
        st.pop();
        ans.push_back(x->val);
        if(x->right!=NULL)st.push(x->right);
        if(x->left!=NULL)st.push(x->left);

        //now we will check its child and we have to keep the riht node doen 

    }
 }
vector<int> preorderTraversal(TreeNode* root) 
{
    // using stack iterative way 
    vector<int>ans;
    preorder(root,ans);
    return ans;
}
};