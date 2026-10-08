class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int open = 0;
        string ans = "";

        for(char ch : s){

            //'(' -> check the 'open' counter before open++ 
            if(ch == '('){
                if(open > 0) ans += '(';
                open++;
            }
            else if ( ch == ')'){
                //')' -> check the 'open' counter after the open--;
                open--;
                if(open > 0) ans += ')';
            }

            // xxxxx manage multiple line xxxxx

            // if (ch==')') open--;
            // if(open > 0) ans.push_back(ch);
            // if(ch == '(') open++;
        }
        return ans;
    }
};