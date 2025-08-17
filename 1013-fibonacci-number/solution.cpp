class Solution {
public:
    int fib(int n) {
        // if (n==0 || n==1 ) return n;
        // return fib(n-1)+fib(n-2);
        if (n == 0) return 0;
        if (n == 1) return 1;

        int first = 0, second = 1, next = 0;
        for (int i = 2; i <= n; i++) {
            next = first + second;
            first = second;
            second = next;
        }
        return second;
    }
};
