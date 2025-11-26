class Solution {
public:
    string compressedString(string word) {
        int n = word.length();
        string ans = "";
        for(int i=0 ; i<n ;){

            int count = 0;
            char current = word[i];
            
            while(i<n && current == word[i] && count <9){
                count++;
                i++;
            }
            ans += to_string(count) + current;    
        }
        return ans;
    }
};