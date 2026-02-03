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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;

        ListNode* before = new ListNode(-1);
        ListNode* beforeTail = before;

        ListNode* after = new ListNode(-1);
        ListNode* afterTail = after;

        ListNode* curr = head;

        while(curr){

            if(curr->val < x) {

                beforeTail -> next = curr;
                beforeTail = beforeTail -> next;
            }else{

                afterTail -> next = curr;
                afterTail = afterTail -> next;
            }
            curr = curr->next;
        }
        afterTail-> next = NULL;
        beforeTail -> next = after->next;
        return  before->next;

    }
};