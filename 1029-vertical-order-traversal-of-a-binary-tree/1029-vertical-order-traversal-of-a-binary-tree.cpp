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
    //    bfs   se  kiya hai 
    vector<vector<int>> verticalTraversal(TreeNode* root) 
{
    // Ye map banate hai jisme sab kuch store hoga - 
    // pahla int (vertical line number), doosra map (level se related), 
    // aur teesra multiset (ek level par agar same value aaye toh sorted rahe).
    map<int, map<int, multiset<int>>> myMap;
    
    // Queue banate hai level order traversal ke liye.
    queue<pair<TreeNode*, pair<int, int>>> q;

    // Final answer store karne ke liye vector.
    vector<vector<int>> ans;

    // Agar root NULL hai toh seedha empty vector return karenge.
    if(root == nullptr) return ans;

    // Queue me root ko initial (0, 0) position ke saath daal rahe hai.
    q.push({root, {0, 0}});

    // Level order traversal shuru karte hai jab tak queue khali na ho jaye.
    while(!q.empty())
    {
        // Front element nikaalte hai queue se.
        auto x = q.front();
        q.pop();
        
        // Node ko extract karte hai aur uske vertical aur level ko bhi.
        TreeNode* node = x.first;
        int vertical = x.second.first;
        int level = x.second.second;

        // Node ka value insert karte hai correct vertical aur level par.
        myMap[vertical][level].insert(node->val);

        // Agar left child exist karta hai toh usko queue me push karte hai, 
        // vertical - 1 aur level + 1 ke saath.
        if(node->left != nullptr) 
            q.push({node->left, {vertical - 1, level + 1}});
        
        // Agar right child exist karta hai toh usko queue me push karte hai, 
        // vertical + 1 aur level + 1 ke saath.
        if(node->right != nullptr) 
            q.push({node->right, {vertical + 1, level + 1}});
    }

    // Ab map ke har element ke liye traverse karte hai.
    for(auto it : myMap)
    {
        vector<int> temp;  // Temporary vector banate hai ek vertical ke liye.
        
        // Har level ke nodes ko uthate hai aur multiset ke through sorted values nikaalte hai.
        for(auto j : it.second)
        {
            for(auto k : j.second) 
                temp.push_back(k);  // Sorted elements ko temp vector me daalte hai.
        }

        // Temp vector ko final ans me push karte hai.
        ans.push_back(temp);
    }

    return ans;  // Answer return karte hai jo vertical order me hai.
}
};
