class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i = 0, j = 0;
        int n1 = v1.size();
        int n2 = v2.size();

        while (i < n1 || j < n2) {
            long long a = 0, b = 0;

            while (i < n1 && v1[i] != '.') {
                a = a * 10 + (v1[i] - '0');
                i++;
            }

            while (j < n2 && v2[j] != '.') {
                b = b * 10 + (v2[j] - '0');
                j++;
            }

            if (a < b) return -1;
            if (a > b) return 1;

            i++;
            j++;
        }

        return 0;
    }
};