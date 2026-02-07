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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || !head->next || k==0) return head;

        ListNode* tail = head;
        int len = 1;
        while(tail -> next != NULL){
            tail =  tail -> next;
            len++;
        }

        if(k % len == 0) return head;
        
        k = k % len;

        // make it circular
        tail -> next = head;

        int stepToNewTail = len - k;

        ListNode* newtail = head;
        
        for(int i=1; i<stepToNewTail ; i++ ){
            newtail = newtail -> next;
        }

        // mark new head
        ListNode* newhead = newtail->next;

        newtail->next = NULL ; // break the link

        return newhead;

    }
};