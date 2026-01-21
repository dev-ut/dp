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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        // ListNode*tempA=l1;
        // ListNode*tempB=l2;
        // //wee willll create the another liat in which sum will be stored
        // ListNode* c= new ListNode(-1);
        // ListNode* tempc=c;               // pointer to the new list
        // int carry =0;
        // while(tempA!=NULL || tempB!=NULL)
        // {
        //    int sum=0+carry;   // hr eak node ke liye naya sum

        //    if(tempA!=NULL)
        //    {
        //        sum=sum+tempA->val;
        //        tempA=tempA->next;
        //    }
        //     if(tempB!=NULL)
        //    {
        //        sum=sum+tempB->val;
        //        tempB=tempB->next;
        //    }
        //    //now look if tehres any carry and u have to fill the last digit of the no so here we will going to use mod and devide

        //    carry=sum/10;
        //    sum=sum%10;
        //    // now we have alrady created a new list make a new  node and insert it in a list
        //    tempc->next=new ListNode(sum);
        //    tempc=tempc->next;
        // }


        //  if (carry > 0)    // bhiya ki last node m agr carry bcha hai to use ek nya node bna kr new list se attach kr do
        //  {
        //    tempc->next = new ListNode(carry);
        //  }
         
        //  tempc=c;
        //  return tempc->next;

         // fir se code 
         ListNode * t1=l1;
         ListNode * t2=l2;
         ListNode *c=new ListNode(-1);
         ListNode* tempc=c;
         int carry=0;
         while(t1!=NULL || t2!=NULL)
         {
            int sum=0+carry;
            if(t1!=NULL)
            {
                sum=sum+t1->val;
                t1=t1->next;
            }
            if(t2!=NULL)
            {
                sum=sum+t2->val;
                t2=t2->next;
            }

            carry=sum/10;
            sum=sum%10;
            tempc->next=new ListNode(sum);
            tempc=tempc->next;
        }
        if(carry>0)
        {
            tempc->next=new ListNode(carry);
        }
        tempc=c;
        return tempc->next;



    }
};