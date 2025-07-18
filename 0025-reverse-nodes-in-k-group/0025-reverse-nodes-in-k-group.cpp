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
    ListNode* reverseKgp(ListNode* head, int k, int size) {
        // base case
        if (size < k) return head;

        int count = 0;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        while (count < k && curr != nullptr) 
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        if (next != nullptr) 
        {
            head->next = reverseKgp(next, k, size - k);
        }
        
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }

        return reverseKgp(head, k, size);
    }
};
