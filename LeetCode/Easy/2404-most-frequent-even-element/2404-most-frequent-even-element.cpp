class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>even;
        int n = nums.size();
    
        for(int i=0 ; i<n ;i++){
            
            if (nums[i]%2==0){
                even[nums[i]]++; 
            }
            
        }
        int maxfreq = 0  , ans = -1;
        for(auto [num,count] : even){
            if(count > maxfreq){
                maxfreq = count;
                ans = num;
            }
        }
        
        return ans;
    }
};