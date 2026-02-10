class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l=0, r = 0;
        int maxLen = 0;
        int maxFreq = 0;

        int freq[26] = {0};

        while(r < n){

            freq[s[r]- 'A']++;
            maxFreq = max(maxFreq, freq[s[r]- 'A']);

            int len = r-l+1;
            int needReplace = len - maxFreq;

            if(needReplace > k){
                freq[s[l]- 'A']--;
                l++;
            }
            if(needReplace <=k){
                maxLen = max(maxLen, len);
            }
            r++;
        }
        return maxLen;
    }
};