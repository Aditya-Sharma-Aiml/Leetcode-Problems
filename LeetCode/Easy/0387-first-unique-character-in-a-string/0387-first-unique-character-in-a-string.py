class Solution:
    def firstUniqChar(self, s: str) -> int:
        from collections import Counter
        f = Counter(s)
        for i, c in enumerate(s):
            if f[c] == 1:
                return i
        return -1
