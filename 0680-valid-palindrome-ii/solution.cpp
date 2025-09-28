class Solution {
    bool ispal(int l, int r, string& s) {
        while (l < r) 
        {
            if (s[l] != s[r]) 
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r && s[l] == s[r])
        {   
            l++;
            r--;
        }
        return ispal(l + 1, r, s) || ispal(l, r - 1, s);
    }
};
