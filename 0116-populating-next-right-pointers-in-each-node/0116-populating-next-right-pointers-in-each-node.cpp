/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        queue<Node*>q;
        if(root!=NULL)q.push(root);

        while(q.size()>0)
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                Node* x=q.front();
                q.pop();
                
                 if(i==s-1)
                   {
                     x->next=NULL;
                    
                   }               
                if(i!=s-1) x->next=q.front();   

                if(x->left!=NULL)q.push(x->left);
                if(x->right!=NULL)q.push(x->right);
            }
        }
        return root;
    }
};