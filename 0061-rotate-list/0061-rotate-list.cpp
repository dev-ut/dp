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
    ListNode* rotateRight(ListNode* head, int k) 
    {
       if(k==0 || head==NULL || head->next==NULL) return head;
       ListNode * tail=head;
       ListNode* temp=head;
       int size=0;
       while(temp!=NULL)
       {
        if(temp->next!=NULL) tail=tail->next;
        temp=temp->next;
        size++;
       }
       k=k%size;
       if(k==0) return head;
       temp=head;
       // amke it cyclic 
       tail->next=head;
       int it=size-k;
       while(it>1)
       {
        temp=temp->next;
        it--;
       }
       // connct 
       ListNode * nwhead=temp->next;
       temp->next=nullptr;

       return nwhead;

    }
};