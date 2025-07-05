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
    // Agar linked list khaali hai
    if (head == NULL) return NULL;

    int size = 0; // Linked list ki size ko track karne ke liye
    ListNode* temp = head;

    // Linked list ki length calculate karte hain
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }

    // Agar n == size, toh head ko remove karna hai
    if (n == size) 
    {
        ListNode* newHead = head->next; // Naya head set karte hain
        delete head; // Old head ko delete karte hain
        return newHead; // Naya head return karte hain
    }
    
    int m = size - n; // Remove karne ke liye node tak pahuchne ke liye

    temp = head;
    // Pahle se m-1 nodes tak pahuchne ke liye
    while (m > 1)
    {
        temp = temp->next;
        m--;
    }

    // n-th node ko remove karte hain
    ListNode* nodeToDelete = temp->next; // Node jo remove karna hai
    temp->next = temp->next->next; // Link ko update karte hain
    delete nodeToDelete; // Node ko delete karte hain

    return head; // Updated head return karte hain
}

};