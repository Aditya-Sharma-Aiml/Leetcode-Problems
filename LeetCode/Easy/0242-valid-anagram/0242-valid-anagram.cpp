class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length()) return false;

        // count frequency of chars
        vector<int>freq(26,0); // because all are small letters
        // increase  freq
        for(char &ch : s){
            freq[ch-'a']++;
        }
        // decrease freq
        for(char &ch : t){
            freq[ch-'a']--;
        }

        // check all are zero in freq all not
        // if all zero mean both string have same freq of letters
        bool allZeros = all_of(begin(freq),
                                 end(freq),
                                  [](int element){
                                        return element == 0;
                                    });
        return allZeros;
    }

};