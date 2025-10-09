class Solution {
public:
    int reverse(int n){
        int rev = 0;
        while(n>0){
            int digit = n % 10;
            rev = rev *10 + digit;
            n /= 10;
        }
        return rev;
    }
    bool isSameAfterReversals(int num) {
        int rev1 = reverse(num);
        int rev2 = reverse(rev1);
        if (rev2==num) return true;
        return false;
    }
};
