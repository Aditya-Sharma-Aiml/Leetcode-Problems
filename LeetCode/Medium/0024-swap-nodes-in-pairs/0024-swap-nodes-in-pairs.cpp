class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        // // Dummy node to handle head swaps easily
        // ListNode dummy(0);
        // dummy.next = head;

        // ListNode* prev = &dummy;

        // while (prev->next && prev->next->next) {

        //     // Nodes to be swapped
        //     ListNode* first = prev->next;
        //     ListNode* second = prev->next->next;

        //     // Swapping
        //     first->next = second->next;
        //     second->next = first;
        //     prev->next = second;

        //     // Move prev forward
        //     prev = first;
        // }

        // return dummy.next;

        if(!head || !head->next) return head;

        ListNode* second = head->next;

        head->next = swapPairs(second->next);
        
        second->next = head;

        return second;

        
    }
};
