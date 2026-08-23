class Solution {
    private void swap(int i, int j, int[] arr){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public void moveZeroes(int[] nums) {
        int j=-1; 
        int n = nums.length;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1) return;
        for(int i=j+1; i<n ; i++){
            if(nums[i] != 0){
                swap(i, j, nums);
                j++;
            }
        }
    }
}