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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // move kro ye dhyan me rakh ke odd and even length ki LL ho skti hai 
        while(fast != NULL && fast-> next != NULL){

            slow = slow->next; // move 1 step
            fast = fast->next->next; // move two step

            // stop point agar loop paa gye to bs return kr jao
            if(slow == fast) return true;
        }

        // loop nhi paya
        return false;
    }
};