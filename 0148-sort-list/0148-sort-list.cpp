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

ListNode* merge(ListNode *a, ListNode *b)
{
    

    ListNode *c = new ListNode(-1);
    ListNode *tempc = c;

    while(a != NULL && b != NULL)
    {
        if(a->val <= b->val)
        {
            tempc->next = a;
            a = a->next;
        }
        else
        {
            tempc->next = b;
            b = b->next;
        }
        tempc = tempc->next;
    }

    // jo bacha hai attach kar do
    if(a != NULL) tempc->next = a;
    else tempc->next = b;

    return c->next;
}

ListNode* sortList(ListNode* head) 
{
    if(head == NULL || head->next == NULL) 
        return head;

    ListNode *t1 = head;
    ListNode *t2 = head;

    // middle nikal rahe
    while(t2->next != NULL && t2->next->next != NULL)
    {
        t1 = t1->next;
        t2 = t2->next->next;
    }

    ListNode *a = head;
    ListNode *b = t1->next;
    t1->next = NULL;

    // recursion ke results store karo
    a = sortList(a);
    b = sortList(b);

    return merge(a, b);
}
};
