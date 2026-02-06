class Solution {
    public int minRemoval(int[] nums, int k) {
        
        int n= nums.length;
        if(n<2) return 0;
        int left=0;
        int count=0;
        Arrays.sort(nums);
        for(int right=0;right<n;right++){
            while(left<right &&  (long)nums[right]> (long)nums[left]*k){
                left++;
            }
            count= Math.max(count, right-left+1);
        }
        return n-count;
        
    }
}