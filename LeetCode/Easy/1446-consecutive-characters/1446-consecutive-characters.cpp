class Solution {
public:
    int maxPower(string s) {

        int power = 1 , maxpower = 1;
        int n=s.size();

        for(int i=1 ; i<n ; i++){

            if(s[i]==s[i-1]) power++;
            else power = 1;

            maxpower = max(maxpower , power);
        }
        return maxpower;
    }
};