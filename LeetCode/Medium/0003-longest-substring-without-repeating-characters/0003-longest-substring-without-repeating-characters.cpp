class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int n = s.length();

        if(n==0 || n==1) return n;

        int maxLen = 0;
        vector<int>visited(256,-1); // index

        while(right < n ){
            // already visted
            if(visited[s[right]] != -1){
                // kya woh same window mw hai
                if(visited[s[right]] >= left){
                    // left ko that element +1 
                    left = max(visited[s[right]] + 1,left);
                }
            }
            int len = right - left + 1;
            maxLen = max(maxLen, len);

            visited[s[right]] = right;
            right++;
        }
        return maxLen;
    }
};