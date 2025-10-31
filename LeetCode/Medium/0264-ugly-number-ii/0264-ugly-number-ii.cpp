class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int>ugly(n+1,0);
        // ugly[n] -> nth ugly number

        ugly[1] = 1; // first ugly num;
        //pointers on ugly num
        int i2=1, i3=1 , i5=1;

        for(int i=2 ; i<=n ; i++){
            // 1-> find ugly numbers
            int i2Ugly = ugly[i2]*2;
            int i3Ugly = ugly[i3]*3;
            int i5Ugly = ugly[i5]*5;
            //2-> choose min ugly
            int minUgly = min({i2Ugly, i3Ugly, i5Ugly});
            ugly[i] = minUgly;
            //3-> increase pointer jiska ugly tumne choose kiya hai
            if (minUgly==i2Ugly) i2++;
            if (minUgly==i3Ugly) i3++;
            if (minUgly==i5Ugly) i5++;
        }
        return ugly[n];
    }
};