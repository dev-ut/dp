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
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode* slow = head; // Slow pointer
    ListNode* fast = head; // Fast pointer
    bool flag = false; // Cycle detect karne ke liye flag

    // Fast aur slow pointer ko move karte hain
    while (fast != NULL && fast->next != NULL) // Loop jab tak cycle nahi milta
    {
        slow = slow->next; // Slow pointer ko ek step aage badhao
        fast = fast->next->next; // Fast pointer ko do steps aage badhao

        if (fast == slow) // Agar fast aur slow milte hain, to cycle hai
        {
            flag = true; // Cycle detect hua
            break;
        }
    }

    // Agar cycle nahi mila, to NULL return karo
    if (flag == false) 
        return NULL;
    else 
    {
        ListNode* temp = head; // Temporary pointer ko head se shuru karo

        // Cycle ka starting point dhundhne ke liye
        while (temp != slow) // Jab tak dono pointers milte nahi
        {
            slow = slow->next; // Slow pointer ko ek step aage badhao
            temp = temp->next; // Temporary pointer ko ek step aage badhao
        }
        
        // Jab dono pointers milte hain, to yeh cycle ka starting point hai
        return temp;
    }
    }

  
};