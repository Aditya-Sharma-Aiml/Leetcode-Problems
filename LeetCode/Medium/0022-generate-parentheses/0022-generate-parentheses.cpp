class Solution {
public:
    void backtrack(string curr, int open, int close, vector<string>&res, int n){

        if (curr.length() == 2*n){ 
            res.push_back(curr);
            return ;
        }
        // choice 1 : generate next ( -> if open < n (bcoz open == n == close)
        if (open < n) backtrack(curr + '(', open+1, close, res, n);
        //choice 2 : generate next ) -> if open > close : to mke valid parentheses
        if (open > close) backtrack(curr + ')', open, close+1, res, n);

    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        backtrack("", 0, 0, res, n);
        return res;
    }
};