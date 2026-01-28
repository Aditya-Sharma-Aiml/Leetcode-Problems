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
    ListNode* getKthNode(ListNode* temp, int k){
        k -= 1;
        while(k>0 && temp){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverse(ListNode* temp){
        if(!temp || !temp->next) return temp;

        ListNode* backward = NULL;
        ListNode* curr = temp;
        while(curr){
            ListNode* forward = curr->next;
            curr->next = backward;
            backward = curr;
            curr = forward;
        }
        return backward;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = head;
        ListNode* prevLast = NULL; // point to prev of next node

        while(temp){

            //1) phle kth node pao
            ListNode* kthNode = getKthNode(temp, k);
            //jb kth node NULL ho mtlb remaining node < k ho
            if(kthNode == NULL){
                //tb bs link kro no reverse
                // but jb prev NULL na ho kyonki null ka next nullptr error d
                if(prevLast) prevLast->next = temp; 
                break;
            }
            
             // store next of kth for furthor revrese tracking
            ListNode* nextNode = kthNode->next;

            kthNode->next = NULL; //break link to reverse
            reverse(temp);

            // agar phla reverse hai toh head ko update krna hoga
            if(temp == head) head = kthNode;
            else{
                prevLast -> next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;

        }
        return head;

    }
};