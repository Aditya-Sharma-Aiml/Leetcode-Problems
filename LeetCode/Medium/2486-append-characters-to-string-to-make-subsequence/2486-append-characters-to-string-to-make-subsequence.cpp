class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0, j=0;
        int n = s.length();
        int m = t.length();

        while(i<m && j<n){
            if(t[i] == s[j]){
                i++;
                j++;
            }
            else
                j++;
        }
        return m-i;   
    }
};