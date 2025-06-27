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
    queue<TreeNode*> q; // Ek queue banate hain, jo tree ke nodes ko level-wise store karegi

    vector<vector<int>> fans; // Final answer ke liye ek 2D vector

    if (root != nullptr) 
    { // Agar root null nahi hai tabhi process karte hain
        q.push(root); // Root ko queue mein daalte hain
    }

        while (!q.empty()) 
        { // Jab tak queue khali nahi ho jaati, level-wise process karte rahenge
            int size = q.size(); // Har level par kitne nodes hain uska size lete hain
            vector<int> ans; // Ek vector jo current level ke nodes ko store karega

            for (int i = 0; i < size; ++i) 
            { // Har level ke nodes ko process karenge
                TreeNode* node = q.front(); // Queue ke front node ko nikaalte hain
                q.pop(); // Us node ko queue se hata dete hain
                ans.push_back(node->val); // Current node ka value ans vector mein store karte hain
                if (node->left != nullptr) q.push(node->left); // Agar left child hai to queue mein daal do
                if (node->right != nullptr) q.push(node->right); // Agar right child hai to bhi queue mein daal do
            }
            
            fans.push_back(ans); // Current level ke nodes ko final answer mein daal dete hain
        }
    
    return fans; // Final answer return karte hain
}
    
};