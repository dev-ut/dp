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
    int widthOfBinaryTree(TreeNode* root) 
    {
    //   if(root==NULL) return 0;
    //   queue<pair<TreeNode*,long long>>q;
    //   int mxwidth=0;
    //   q.push({root,0});
    //   while(q.size()>0)
    //   {
    //     int size=q.size();
    //     long long leftmostindx=q.front().second;
    //     long long rightmostindx=q.back().second;
    //     mxwidth =max(mxwidth,(int)rightmostindx - leftmostindx +1);

    //     for(int i=0;i<size;i++)
    //     {
    //         TreeNode* x=q.front().first;
    //         long long indx=q.front().second;
    //         q.pop();

    //         if(x->left!=NULL)q.push({x->left,2*indx});
    //         if(x->right!=NULL)q.push({x->right,2*indx+1});

    //     }
    //   }

    //   return mxwidth;

      if (!root) return 0; // Agar root null hai toh width 0 hogi.

    // BFS traversal karenge nodes aur unke index ke saath queue mein store karke.
    queue<pair<TreeNode*, long long>> q;
    q.push({root, 0});
    int mxwidth = 0;

    while (!q.empty()) 
    {
        int size = q.size();
        long long leftmost_indx = q.front().second; // Current level ke leftmost index le lo.
        long long rightmost_indx = q.back().second; // Current level ke rightmost index le lo.
        mxwidth = max(mxwidth, (int)(rightmost_indx - leftmost_indx + 1)); // Max width ko update karenge.

        for (int i = 0; i < size; i++) 
        {
            TreeNode* node = q.front().first; // Current node le lo.
            long long indx = q.front().second - leftmost_indx; // Relative index le lo.
            q.pop();

            // Left child agar hai toh usko queue mein daaldo.
            if (node->left != nullptr) q.push({node->left, 2 * indx});
            
            // Right child agar hai toh usko queue mein daaldo.
            if (node->right != nullptr) q.push({node->right, 2 * indx + 1});
        }
    }

    return mxwidth; // Max width return karenge.
    }
};