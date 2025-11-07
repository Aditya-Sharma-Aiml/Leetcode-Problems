class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        //1 -> reverse entire string
        reverse(s.begin(), s.end());

        for(int i=0 ; i<n ; i++){

            string word = "";

            while(i<n && s[i] != ' '){
                word += s[i];
                i++;
            }
            //2-> reverese each words
            reverse(word.begin(), word.end());

            if(word.size() > 0){
                ans += " "+ word; 
            }

        }
        return ans.substr(1); // skip 1st char that is space
    }
};