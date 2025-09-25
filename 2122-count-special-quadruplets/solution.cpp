class Solution {
public:
    int countQuadruplets(vector<int>& nums) {

      int c=0,n=nums.size();
      unordered_map<int,int>mp;

      for(int i=1;i<n;i++){

        for(int j=0;j<i;j++){

            mp[nums[i]+nums[j]]++;
        }
        for(int k=i+2;k<n;k++){
            
            c+=mp[nums[k]-nums[i+1]];
        }
      }
        return c;
    }
};
