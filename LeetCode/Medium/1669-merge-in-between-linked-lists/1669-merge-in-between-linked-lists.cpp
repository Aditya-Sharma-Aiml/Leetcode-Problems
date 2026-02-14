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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
  
        ListNode* curr = list1;
        ListNode* start = NULL;
        ListNode* end = NULL;

        int idx = 0;

        while(curr){

            if(idx == a-1){
                start = curr;
            }
            if(idx == b){
                end = curr->next;
                curr->next = NULL ;
                break;

            }
            curr= curr->next;
            idx++;
        }

        ListNode* temp = list2;
        while(temp->next){
            temp = temp->next;
        }

        temp->next = end;
        start->next = list2;
        return list1;
    
    }
};