class Solution {
public:
    long long countSubstrings(string s, char c) {
        
        long long count = 0 ;
        long long ans = 0 ;

        for(int i=0 ; i<s.length() ; i++){
            // phle str me kitne c aaye hai unke sath substr aor khud 
            if ( s[i] == c && count >=0){

                ans += count;
                ans++;
                count++;
            }
        }
        return ans ;
    }
};