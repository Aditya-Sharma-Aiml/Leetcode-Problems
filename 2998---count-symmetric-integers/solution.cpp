class Solution {
    bool isSymmetric(int n) {

        auto s = to_string(n);
        if (s.size() % 2) return false;
        int N = s.size(), first = 0, second = 0;
        
        for (int i = 0; i < N; ++i) {
            if (i < N / 2) first += s[i] - '0';
            else second += s[i] - '0';
        }
        return first == second;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low ; i <= high; ++i) ans += isSymmetric(i);
        return ans;
    }
};
