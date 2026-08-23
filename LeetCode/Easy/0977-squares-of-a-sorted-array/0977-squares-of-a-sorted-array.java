class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] square = new int[n];

        int left = 0 , right = n -1;
        int pos = n-1;

        while(left <= right){
            int leftSqr = nums[left]*nums[left];
            int rightSqr = nums[right]*nums[right];

            if(leftSqr > rightSqr){
                square[pos] = leftSqr;
                left++;
            }
            else {
                square[pos] = rightSqr;
                right--;
            }
            pos--;

        } 
        return square;
    
    }
}