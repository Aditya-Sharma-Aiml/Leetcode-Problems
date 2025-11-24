class Solution {
public:
    long long countSubstrings(string s, char c) {
        
        //char c ...kuch bhi.... char c
        //total = char c count + char cCount C 2
        // cCount C 2 = cCount(cCount+1)/2;
        int cCount = 0;
        for(char ch : s){
            if(ch==c) cCount++;
        }
        long long cC2 = cCount * (cCount-1) / 2;
        long long ans = cC2 + cCount;
        return ans;

    }
};