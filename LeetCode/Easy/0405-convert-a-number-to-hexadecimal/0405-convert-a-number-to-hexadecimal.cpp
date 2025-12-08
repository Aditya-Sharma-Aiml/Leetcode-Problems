class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        unsigned int n = num;
        string d = "0123456789abcdef", ans = "";
        while(n){
            ans = d[n & 15] + ans;
            n >>= 4;
        }
        return ans;
    }
};
