/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* tempa=headA;
        ListNode* tempb=headB;
        int lena=0;
        int lenb=0;
        while(tempa!=NULL || tempb!=NULL)
        {
            if(tempa!=NULL)
            {
                lena++;
                tempa=tempa->next;
            }
             if(tempb!=NULL)
            {
                lenb++;
                tempb=tempb->next;
            }
        }
        tempa=headA;
        tempb=headB;
        int diff=0;
        if(lena>lenb)
        {
            diff=lena-lenb;
            for(int i=0;i<diff;i++)
            {
                tempa=tempa->next;
            }
        }
        else
        {
           diff=lenb-lena;
            for(int i=0;i<diff;i++)
            {
                tempb=tempb->next;
            } 
        }
        while(tempa!=tempb)
        {
            tempa=tempa->next;
            tempb=tempb->next;
        }
        return tempa;

    }
};