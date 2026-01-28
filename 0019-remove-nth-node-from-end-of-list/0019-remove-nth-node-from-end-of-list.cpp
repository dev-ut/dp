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
ListNode* removeNthFromEnd(ListNode* head, int n) 
{

    int size=0;
    ListNode* temp=head;
    while(temp!=NULL)
    {
        size++;
        temp=temp->next;
    }
    temp=head;
    // if head node hi delet krna hua to 
    if(size==n)
    {
        ListNode * newhead=head->next;
        delete head;
        return newhead;
    }
    int it=size-n;
    while(it-1>0)
    {
        temp=temp->next;
        it--;
    }
    // connection and deletion 
    ListNode* del=temp->next;
    temp->next=del->next;
    delete del;

    return head;

//    int size=0;
//    ListNode *temp=head;
//    if(head==NULL) return NULL;
//    while(temp!=NULL)
//    {
//     size++;
//     temp=temp->next;
//    } 

//    // if agr head hi remove krna pda to 
//    if(n==size)
//    {
//     ListNode* newhead=head->next;
//     delete head;
//     return newhead;
//    }
//    int it=size-n;
//    temp=head;
//    for(int i=0;i<it-1;i++)
//    {
//     temp=temp->next;
//    }
//    ListNode* del=temp->next;
//    temp->next=temp->next->next;
//    delete del;

//    return head; 
}

};