class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // hare and tortoise method
        int slow = nums[0];
        int fast = nums[0];

        // cycle detect
        do{
            slow = nums[slow]; // 1-step
            fast = nums[nums[fast]]; // 2-step
        }while(slow != fast);

        // find starting point of cycle => duplicate
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow]; // 1-step
            fast = nums[fast]; // 1-step
        }
        return slow;// fast

    }
};