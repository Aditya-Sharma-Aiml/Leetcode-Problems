class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // similar as >n/2 time but check if nums[i] already in element1 then it should not go for element2
        int count1 = 0 , count2 = 0;
        int element1 = INT_MIN;
        int element2 = INT_MIN;
        int n = nums.size();

        for(int i=0 ; i<n ;i++){

            if(count1==0 && nums[i] != element2){
                count1 = 1;
                element1 = nums[i];
            }
            else if(count2==0 && nums[i] != element1){
                count2 = 1;
                element2 = nums[i];

            }
            else if(nums[i] == element1) count1++;
            else if(nums[i] == element2) count2++;

            else {
                count1--;
                count2--;
            }
        }
        // explicitely check element1 and element2 are possible ans or not
        vector<int>ans;
        int cnt1 = 0 , cnt2 = 0;
        for(int i=0 ; i<n ;i++ ){

            if (nums[i]==element1) cnt1++;
            if (nums[i]==element2) cnt2++;    

        }  

        int mini = (int)(n/3)+1;
        if (cnt1>=mini) ans.push_back(element1);
        if (cnt2>=mini) ans.push_back(element2);
        return ans;
    }
};
