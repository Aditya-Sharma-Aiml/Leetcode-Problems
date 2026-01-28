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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;

        ListNode* curr = head;

        while(curr){

            if(curr->next && curr->val == curr->next->val){

                int dupVal = curr->val;

                while(curr && curr->val == dupVal){
                    ListNode* temp = curr;   
                    curr = curr->next;
                    delete temp;
                }
                prev->next = curr;
            }
            else{
                prev=curr;
                curr = curr->next;
            }

        }
        return dummy->next;
    }
};