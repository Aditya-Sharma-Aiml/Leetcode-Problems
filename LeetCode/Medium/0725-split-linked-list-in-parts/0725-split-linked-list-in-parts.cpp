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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        vector<ListNode*>ans;

        if(!head ) {
            while(k--)
                ans.push_back(NULL);
            return ans;
        }

        ListNode* curr = head;
        int total = 0;

        while(curr){

            total++;
            curr = curr->next;
        }

        int eachPart = total / k;
        int remainingPart = total % k;

        if(k > total){
            eachPart = 1;
            remainingPart = k - total;
        }

        ListNode* nextNode = head;
        ListNode* prevNode = head;
        curr = head;
        int temp = eachPart;

        if(eachPart == 1){

            while(curr){

                nextNode = curr->next;
                curr->next = NULL;
                ans.push_back(prevNode);
                prevNode = nextNode;
                curr = nextNode;

            }
            while(remainingPart){
                remainingPart--;
                ans.push_back(NULL);
            }

            return ans;
        }

        while(curr){

            if(remainingPart != 0 && remainingPart){
                remainingPart--;
                curr = curr->next;
            }
            while(temp > 1){
                temp--;
                curr=curr->next;
            }

            temp = eachPart;

            nextNode = curr->next;
            curr->next = NULL;
            ans.push_back(prevNode);
            prevNode = nextNode;
            curr = nextNode;
        }
        return ans;
    }
};