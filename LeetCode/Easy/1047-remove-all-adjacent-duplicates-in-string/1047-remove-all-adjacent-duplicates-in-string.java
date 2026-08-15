class Solution {
    public String removeDuplicates(String s) {

        StringBuilder ans = new StringBuilder();

        for(char ch : s.toCharArray()){

            if(ans.length() != 0 && ans.charAt(ans.length()-1)==ch){
                ans.deleteCharAt(ans.length() - 1);
            }
            else{
                ans.append(ch);
            }
        }
        return ans.toString();
        
    }
}