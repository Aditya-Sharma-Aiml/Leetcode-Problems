class Solution {
    public String largestOddNumber(String num) {

        int endIdx = -1;
        for(int i=num.length()-1 ; i>=0; i--){

            if((num.charAt(i)-'0')%2==1){
                endIdx = i;
                break;
            }
        }

        // // remove leading zeros
        // int startIdx = 0;
        // while(startIdx < num.length()){
        //     if(num.charAt(startIdx)=='0') startIdx++;
        //     else break;
        // }

        return num.substring(0, endIdx+1);
    
    }
}