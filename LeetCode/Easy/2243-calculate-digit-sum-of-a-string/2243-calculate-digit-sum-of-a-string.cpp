class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string ans = "";
            int n = s.size();
            for(int i=0 ; i<n ; i+=k){
                int temp = 0;
                for(int j=i ; j<i+k && j<n ; j++){
                    temp += s[j]-'0';
                } 
                ans += to_string(temp);
            }
            s = ans;
        }
        return s;
    }
};