class Solution {
public:
    string addBinary(string a, string b) {

        int carry = 0;
        int i = a.length()-1;
        int j = b.length()-1;
        string ans = "";

        while(i>=0 || j>=0 || carry){
            // next sum krne se phle purane carry ko add kr do
            int sum = carry;
            if(i>=0) sum += a[i--]-'0'; // add first bit num
            if(j>=0) sum += b[j--]-'0'; // add second bit num

            ans += (sum % 2 + '0'); // ans me result dalo
            carry = sum / 2; //carry ko update kro
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};