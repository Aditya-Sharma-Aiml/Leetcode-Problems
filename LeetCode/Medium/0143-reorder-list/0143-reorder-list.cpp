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
    ListNode* reverse(ListNode* head)
    {
        if(!head || !head->next) return head;

        ListNode* curr = head;
        ListNode* forw = NULL;
        ListNode* back = NULL;

        while(curr){
            forw = curr->next;
            curr->next = back;
            back = curr;
            curr=forw;
        }
        //imp
        return back;

    }
    void reorderList(ListNode* head) {
        
        // break from middle 
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* right = slow -> next;
        slow -> next = NULL; // break link

        ListNode* left = head;
        right = reverse(right);

        ListNode* nextLeft = NULL;
        ListNode* nextRight = NULL;

        while(right != NULL){
            nextLeft = left->next;
            nextRight = right->next;
            
            left->next = right;
            right->next = nextLeft;

            left = nextLeft;
            right = nextRight;
        }

    }
};