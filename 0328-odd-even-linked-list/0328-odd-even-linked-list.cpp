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
    ListNode* oddEvenList(ListNode* head) 
    {
         if (!head || !head->next) // If the list is empty or has only one node, no need to process
            return head;

        int count = 1; // Start counting from the first node
        ListNode *oddHead = new ListNode(0); // Dummy node for odd list
        ListNode *evenHead = new ListNode(0); // Dummy node for even list
        ListNode *oddTail = oddHead; // Pointer to the last node in the odd list
        ListNode *evenTail = evenHead; // Pointer to the last node in the even list
        ListNode *curr = head; // Pointer to traverse the original list

        while (curr) {
            if (count % 2 == 1) {
                oddTail->next = curr; // Append the current node to the odd list
                oddTail = oddTail->next; // Move the tail pointer
            } else {
                evenTail->next = curr; // Append the current node to the even list
                evenTail = evenTail->next; // Move the tail pointer
            }
            curr = curr->next; // Move to the next node in the original list
            count++; // Increment the count
        }

        evenTail->next = nullptr; // Terminate the even list
        
        oddTail->next = evenHead->next; // Connect the odd list to the even list
        ListNode *result = oddHead->next; // Resultant list starts from the first node of odd list
        
        // Free the dummy nodes
        delete oddHead;
        delete evenHead;
        
        return result;


        // ??let me do it gain 
        //  if(head==NULL || head->next==NULL) return head;

        //  ListNode * oddhead=new ListNode(0);
        //  ListNode *evenhead=new listNode(0);
        //  ListNode*eventail=evenhead;
        //  ListNde * oddtail=oddhead;

        //  ListNode* it=head;

        //  int indx=1;
        //  while(it!=NULL)
        //  {
        //     if(indx%2!=0)
        //     {
        //       oddtail->next=it;
        //       oddtail=oddtail->next;
        //     }
        //     else
        //     {
        //        eventail->next=it;
        //       eventail=eventail->next;
        //     }
        //     count++;
        //     it=it->next;
        //  }
        //  eventail->next=NULL;
        // // now we are going to connect 
        // oddhead->next=evenhead->next

    }
};