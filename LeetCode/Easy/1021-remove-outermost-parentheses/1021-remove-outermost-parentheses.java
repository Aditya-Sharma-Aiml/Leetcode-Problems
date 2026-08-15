class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder ans = new StringBuilder();

        Stack<Character> st = new Stack<>();
        for(char ch : s.toCharArray()){

            if(ch == '('){

                if(!st.isEmpty()) ans.append(ch);
                st.push(ch);

            }
            else if (ch == ')'){
                st.pop();
                if(!st.isEmpty()) ans.append(ch);
            }
        }
        return ans.toString();
    }
}