class Solution {
public:
    bool checkPalindrome(string &str, int start, int end){
         if (start >= end) return true;
        if (str[start] != str[end]) return false;
        return checkPalindrome(str, start + 1, end - 1);

    }
    bool isPalindrome(string s) {
        string str; 
        for(char c : s){
        if(isalnum(c))          
            str.push_back(tolower(c));  
    }
        return checkPalindrome(str, 0, str.size() - 1);
        
    }
};
