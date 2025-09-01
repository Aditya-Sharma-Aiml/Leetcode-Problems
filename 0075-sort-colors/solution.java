class Solution {
    public void sortColors(int[] nums) {
        int first=0;
        int mid=0;
        int last=nums.length-1;

       while(mid<=last){
        if(nums[mid]==0){
            swap(nums,first,mid);
            first++;
            mid++;
        }else if(nums[mid]==1){
            
            mid++;

        }else{
            swap(nums,mid,last);
            last--;

        }
        
        }
       }
       private  void swap(int[]nums,int i,int k){
            int temp= nums[i];
               nums[i]=nums[k];
               nums[k]=temp;
        
    }
}
