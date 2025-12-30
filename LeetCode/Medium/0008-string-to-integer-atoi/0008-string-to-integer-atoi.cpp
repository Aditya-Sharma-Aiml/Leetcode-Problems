class Solution {
public:
    int helper(string s , int i , int num , int sign){
        int n = s.size();
        if (i>=n || !isdigit(s[i])){
            return (int)(sign*num);
        }

        num = num*10 + (s[i]-'0');

        // if ans > INT_MAX : OVERFLOW OCCUR
        if(i<n && (sign * num) > INT_MAX) return INT_MAX;
        //if ans < INT_MIN : UNDERFLOW OCCUR
        if(i<n && (sign * num) < INT_MIN ) return INT_MIN;

        return helper(s,i+1,num,sign);
    }
    int myAtoi(string s) {
        
        int n = s.length();
        // 1-> skip leading spaces
        int i=0;
        while(i<n && s[i] == ' ') i++;

        //2->determine sign and move to next char
        int sign = 1;
        if(s[i] == '-'){
            sign = -1 ;
            i++;
        }
        else if(s[i] == '+') i++;

        // if non-digit found(all are spaces) return 0
        if(i == n) return 0;

        // // xxxxxxxxxxx xxxxxxxxxxxx xxxxxxxxxxxxxxxx

        // long long ans = 0;
        // //3-> read all digit untill we get non-digit
        // while(i<n && isdigit(s[i])){

        //     ans = ans * 10 + (s[i] - '0');

        //     //4-> overflow/underflow:
        //     //if ans > INT_MAX : OVERFLOW OCCUR
        //     if(i<n && (sign * ans) > INT_MAX) return INT_MAX;
        //     //if ans < INT_MIN : UNDERFLOW OCCUR
        //     if (i<n && (sign * ans) < INT_MIN ) return INT_MIN;

        //     i++;
        // }
        // return (int)(sign * ans);
        // // xxxxxxxxxxx xxx xxxxxxxxxxxxxxxxxxxxx
        return helper(s,i,0,sign);
    }
};