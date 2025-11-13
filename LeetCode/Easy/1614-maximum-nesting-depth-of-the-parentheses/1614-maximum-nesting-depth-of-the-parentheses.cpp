class Solution {
public:
    int maxDepth(string s) {
        
        int openBrackets = 0;
        int depth = 0;

        for(char ch : s){
            // ( -> we are going deeper 
            if(ch == '(') openBrackets++;
            // ) -> we are getting out
            else if(ch == ')') openBrackets--;

            // maxdepth maximum of openBrackets 
            depth = max(depth, openBrackets); 

        }
        return depth;
    }
};