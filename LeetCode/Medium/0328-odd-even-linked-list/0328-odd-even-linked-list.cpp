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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;               // start of odd list
        ListNode* even = head->next;        // start of even list
        ListNode* evenHead = even;          // save for later

        // rearrange links until no more even next
        while (even && even->next) {
            odd->next = even->next;         // link odd to next odd
            odd = odd->next;

            even->next = odd->next;         // link even to next even
            even = even->next;
        }

        odd->next = evenHead;               // connect end of odd to start of even
        return head;
    }
};
