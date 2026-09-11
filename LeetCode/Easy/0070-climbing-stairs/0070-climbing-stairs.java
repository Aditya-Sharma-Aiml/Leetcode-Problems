class Solution {
    public int climbStairs(int n) {
        // if(n<0) return 0;
        // if(n==0) return 1;
        // return climbStairs(n-1) + climbStairs(n-2);

        if(n==1 || n==2 ) return n;
        int prev1=1;
        int prev2=2;
        int curr;

        for(int i=3; i<=n; i++){
            curr = prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        return prev2;

    }
}