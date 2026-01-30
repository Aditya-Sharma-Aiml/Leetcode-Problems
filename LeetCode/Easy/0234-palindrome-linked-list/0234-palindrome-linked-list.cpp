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
private:
   ListNode* reverseLL(ListNode* head){

        if(head == NULL || head -> next == NULL) return head;

        ListNode* back = NULL;
        ListNode* curr = head;

        while(curr != NULL){

            ListNode* forw = curr -> next;
            curr -> next = back;
            back = curr;
            curr = forw;
        }
        // vimp 
        return back; // as newHead

   }
public:
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head -> next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head->next;

        // find mid1
        while(fast != NULL && fast -> next!= NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        // reverse the next part of LL
        ListNode* newHead = reverseLL(slow -> next);

        // comparing 
        ListNode* first = head; // pointer to first part
        ListNode* second = newHead; // pointer to second part

        while(second != NULL){

            if(first -> val != second -> val){

                // first obtain original LL
                reverseLL(newHead);
                return false;
            }
            first = first -> next;
            second = second -> next;
        }
        reverseLL(newHead);
        return true;
    }
};