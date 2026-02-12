class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                // find first non-zero frequency
                int target = 0;
                for (int f : freq) {
                    if (f > 0) {
                        target = f;
                        break;
                    }
                }

                // check if all non-zero frequencies are equal
                bool balanced = true;
                for (int f : freq) {
                    if (f > 0 && f != target) {
                        balanced = false;
                        break;
                    }
                }

                if (balanced) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
