class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
    while (left < right) { // keep shifting until they match
        left >>= 1;
        right >>= 1;
        shift++;
    }
    return left << shift;
    }
};
