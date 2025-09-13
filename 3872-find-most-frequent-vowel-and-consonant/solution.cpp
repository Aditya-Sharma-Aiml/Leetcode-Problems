class Solution {
public:
    int maxFreqSum(string s) {
        int count_v = 0, count_c = 0;
        unordered_map<char, int> mp;

        for (char c : s) {
            int f = ++mp[c]; 

            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                count_v = max(count_v, f);
            else
                count_c = max(count_c, f);
        }
        return count_v + count_c;
    }
};
