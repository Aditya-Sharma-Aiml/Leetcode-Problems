class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long x, long long n){
        
        if (n==0) return 1;
        if (n==1) return x;

        long long half = power(x,n/2) % MOD;
        long long pow = (half * half) % MOD;
        if (n&1) pow = (pow * x) % MOD;
        return pow;
        

    }
    int countGoodNumbers(long long n) {

        long long totalGood = power(5,(n+1)/2) * power(4,n/2) % MOD;
        return totalGood;
    }
};