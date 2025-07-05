/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) 
    {
        // merge sort is used to specifically mege linked list
        //1.make a node which will contain smaller value .initally containing garbage value
        ListNode *c=new ListNode(-1);
        ListNode *t=c;

        while(a!=NULL && b!=NULL)
        {

            if(a->val<=b->val)
            {
                t->next=a;   //linked a
                a=a->next;
                t=t->next;

            }
            else
            {
                
                t->next=b;   //linked b
                b=b->next;
                t=t->next;
            }
        } 
          // agr a khtm ho gyi ho to
          if(a==NULL) t->next=b;
          else t->next=a;
          return c->next;  // ek farzi node hai na
        
        
    }
};