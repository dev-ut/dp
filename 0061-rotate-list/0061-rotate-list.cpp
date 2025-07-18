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
        if(head==NULL || head->next==NULL) return head;  // edge xase 2
        ListNode* temp=head;
        ListNode *tail=NULL;
        int size=0;
        //get the size of the list  and tail ko end main kr do taki excahnge kr ske

        while(temp!=NULL)
        {
            if(temp->next!=NULL) tail=temp->next;   // tail bhi set hogay
           temp=temp->next;
           size++;
        }

        // temp ko fr se head pr le aao
         k=k%size;   // if(k>n) make it small
        if(k==0) return head;   // edge case 1  that is if k=25 in size of 5 :25%5=0 ie return list
        temp=head;

        for(int i=1;i<size-k;i++)
        {
            temp=temp->next;
        }
        tail->next=head;
        head=temp->next;
        temp->next=NULL;
         
         return head;
        
    }
};