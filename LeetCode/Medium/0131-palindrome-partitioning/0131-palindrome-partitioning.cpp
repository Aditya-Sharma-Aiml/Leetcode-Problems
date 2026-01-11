class Solution {
    private:
    bool isPalindrome(int start, int end, string &s){
        while(start <= end){
            if (s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    void findPartition(int idx, vector<string>&path, string &s, vector<vector<string>>&ans){
        if(idx == s.length()){ // base case
            ans.push_back(path);
        }
        // loop method recursion to check all possibility(idx -> n-1) : i
        for(int i=idx ; i<s.length(); i++){

            if(isPalindrome(idx, i, s)){
                //palindrome then add to path (s.substr(startIdx, lengthOfSubstr))
                path.push_back(s.substr(idx, i-idx+1));
                findPartition(i+1, path, s, ans);

                path.pop_back();// backtrack
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>path;
        findPartition(0, path, s, ans);
        return ans;
    }
};