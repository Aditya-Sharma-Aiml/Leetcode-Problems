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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next || k<1) return head;
        ListNode* end = head;
        int cnt = 0;
        ListNode* start = NULL;
        while(end){
            cnt++;
            if(cnt == k){
                start = end;
            }
            end = end->next;
        }
        int last = cnt - k;
        end = head;
        for(int i=0; i<last; i++){
            end = end -> next;
        }
        swap(end->val, start->val);
        return head;
    }
};