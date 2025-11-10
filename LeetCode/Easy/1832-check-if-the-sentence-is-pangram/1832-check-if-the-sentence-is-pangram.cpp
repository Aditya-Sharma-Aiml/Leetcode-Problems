class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        if(sentence.length() < 26) return false;
        vector<int>freq(26,0);

        for(char ch : sentence){
            freq[ch - 'a']++;
        }
        bool allPresent = all_of(begin(freq),
                                    end(freq),
                                    [](int element){
                                        return element > 0;
                                    });

        return allPresent;
    }
};