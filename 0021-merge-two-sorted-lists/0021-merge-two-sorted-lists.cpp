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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
      ListNode *t1=list1;
      ListNode * t2=list2;
      ListNode * c=new ListNode (-1);
      ListNode * tempc=c;
      while(t1!=NULL && t2!=NULL)
      {
        if(t1->val<=t2->val)
        {
         tempc->next=t1;
         t1=t1->next;
         
        }
        else
        {
          tempc->next=t2;
          t2=t2->next;
          
        }
        tempc=tempc->next;
      }

        if(t1==NULL) tempc->next=t2;

        else tempc->next=t1;
      
      return c->next;    
    }
};