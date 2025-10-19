class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> seen(26, false);
        for (char c : s) {
            if (seen[c - 'a']) return c; // found second occurrence
            seen[c - 'a'] = true;
        }
        return ' '; // should never reach here
    }
};
