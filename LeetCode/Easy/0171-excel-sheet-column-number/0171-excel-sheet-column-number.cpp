class Solution {
public:
    int titleToNumber(string s) {
        long long n = 0;
        for(char c : s)
            n = n * 26 + (c - 'A' + 1);
        return n;
    }
};
