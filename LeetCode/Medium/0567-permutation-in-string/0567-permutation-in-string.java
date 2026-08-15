class Solution {
    public boolean checkInclusion(String s1, String s2) {
        
        //sliding window 
        //freq count method
        // hum kya krenge first freq table me s1 ko store kr lenge 
        // aor fir s1 length ki window bna kr s2 kw freq2 table me comapare krenge 
        // agar exist krta hai toh true wrna last me false
        //jb bhi s1 ki length se window increase  kre window size ghatani hogi

        int[] freq1 = new int[26];
        int[] freq2 = new int[26];

        int k = s1.length();
        int n = s2.length();

        if(k>n) return false;
        
        int r=0, l=0;

        // freq table 1 store s1 
        for(int i=0; i<k; i++){
            char ch = s1.charAt(i);
            freq1[ch-'a']++;
        }
    

        while(r<n){
            char ch2 = s2.charAt(r);

            freq2[ch2-'a']++;

            if(r-l+1 > k){
                char ch1 = s2.charAt(l);
                freq2[ch1-'a']--;
                l++;
            }
            // equal freq return true
            if(r-l+1 <= k && Arrays.equals(freq1, freq2)){
                return true;
            }
            r++;
        }
        return false;

    }
}