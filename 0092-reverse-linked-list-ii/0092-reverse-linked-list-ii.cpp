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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
       // Dummy node banate hain jo list ke head se connected hogi
    ListNode* dummy = new ListNode(-1); // Dummy node bana di - iska koi value nahi hai
    dummy->next = head;  // Dummy node ko original list ke head se connect kar diya

    // Prev ko dummy pe set karte hain initially
    ListNode* prev = dummy;

    // 1 se left tak move karte hain taaki prev left ke ek node pehle position pe ho
    for (int i = 1; i < left; i++) {
        prev = prev->next; // Prev ko left ke ek node pehle le aate hain
    }

    // Current node ko left wale node pe set karte hain
    ListNode* current = prev->next;  // Ye 'left' position wali node hai
    ListNode* nextNode = nullptr;    // Reverse karte waqt agle node ko temporarily store karne ke liye
    ListNode* beforeLeft = prev;     // BeforeLeft node ko save kar lete hain taaki final mein link kar sakein

    // Ab actual reversal start karenge, left se right ke beech tak reverse hoga
    for (int i = left; i <= right; i++) {
        nextNode = current->next; // Next node ko temporarily store kar lo
        current->next = prev;     // Current node ka next ko reverse karte hue prev pe point kar do
        prev = current;           // Prev ko current pe le aao, reverse mein aage badh rahe hain
        current = nextNode;       // Current ko agle node pe le aao
    }

    // Reversed part ko wapas original list ke saath connect karte hain
    beforeLeft->next->next = current; // Reversed list ke last node (jo pehle left tha) ko current (right ke baad ka node) se link kar do
    beforeLeft->next = prev;          // BeforeLeft node ko reversed part ke head se connect karte hain

    // Dummy node ka next return karte hain, jo ab actual head hai
    return dummy->next;  // Head return karo (dummy ke next ko, kyunki dummy khud logical part nahi hai)
}
};