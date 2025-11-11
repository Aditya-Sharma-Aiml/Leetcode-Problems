class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int n = s.size();

        for (int end = 0; end <= n; ++end) {
            if (end == n || s[end] == ' ') {
                // Reverse the current word
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1; // Move to start of next word
            }
        }

        return s;
    }
};