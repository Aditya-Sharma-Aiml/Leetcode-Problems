class Solution {
private: 
    double power(double x, long long n){
        if (n==0) return 1.0;
        if (n==1) return  x;
        if (n&1) return x * power(x,n-1);
        return power(x*x, n/2);
    };
public:
    double myPow(double x, int n) {
        long long exp = n;
        if(exp < 0){
            return(1.0/power(x,-1*exp));
        }
        return power(x,exp);  

    }
        // xxxxxxxxxxx without recursion xxxxxx 
        // long long exp = n;
        
        // if (exp<0){
        //     x=1/x;
        //     exp = -exp;   
        // }
        // double res = 1.0; 
        // while(exp>0){

        //     if(exp&1) {
        //         res*=x;  
        //     }

        //     x*=x;
        //     exp>>=1;
        // }
        
        // return res;

    
};