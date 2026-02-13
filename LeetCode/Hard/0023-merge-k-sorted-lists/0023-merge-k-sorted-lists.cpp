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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (lists.size() == 0) return NULL;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // define min heap
        priority_queue<pair<int,ListNode*>, 
        vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;

        //insert all list in heap
        for(int i=0; i<lists.size(); i++){

            if(lists[i]){
                pq.push({lists[i]->val, lists[i]});
            }
        }

        // merging start untill pq is not empty
        while(!pq.empty()){

            // min heap se min (top) ko nikalo aor pop kr do
            auto it = pq.top(); 
            pq.pop();

            // agar top ka next node exist krta hai 
            //toh usko heap me fir daal do
            if(it.second->next){
                pq.push({it.second->next->val,it.second->next});
            }

            // top ke node ko link kro apne merging process me
            temp->next = it.second;
            //move 
            temp = temp -> next;
        }
        return dummy -> next;

    }
    
};