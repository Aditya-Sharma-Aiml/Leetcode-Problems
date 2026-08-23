class Solution {
    public int removeDuplicates(int[] nums) {
        // HashSet<Integer>set = new HashSet<>();
        // for(int i=0; i<nums.length; i++){
        //     set.add(nums[i]);
        // }
        // int pos = 0;
        // for(int x: set){
        //     nums[pos++] = x;
        // }
        // return pos;
        int j = 0;
        for(int i=0; i<nums.length ; i++){
            if(nums[i] != nums[j]){
                nums[++j] = nums[i];
            }
        }
        return j+1;
    }
}