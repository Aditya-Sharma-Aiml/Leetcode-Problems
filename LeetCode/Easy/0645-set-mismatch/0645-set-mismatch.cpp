class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        int zeros = 0;
        int xr = 0;
        for(int i=0 ; i<n ; i++){
            xr ^= nums[i];
            xr ^= i+1;
                
       }
       int mask = xr & -xr;
       for(int i=0 ; i<n ; i++){
            if(mask & nums[i]) ones ^= nums[i];
            else zeros ^= nums[i];
       }
       for(int i=1 ; i<=n ; i++){
            if(mask & i) ones ^= i;
            else zeros ^= i;
       }
       int count = 0;
       for(int i=0;  i<n ; i++){    
            if (nums[i]==zeros)count ++;

       }
       if(count==2) return {zeros, ones};
       return {ones,zeros};
       
    }
};