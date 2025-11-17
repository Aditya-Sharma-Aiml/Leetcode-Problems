class Solution {
public:
    int beautySum(string s) {
        
        int n = s.length();
        int sum = 0;

        for(int i=0 ; i<n ; i++){

            // subString freq count
            unordered_map<char,int>freq;

            for(int j=i ; j<n ;j++){
                
                freq[s[j]]++;

                int maxi = INT_MIN;
                int mini = INT_MAX;

                //find max and min freq
                for(auto it : freq){
                    maxi = max(maxi, it.second);
                    mini = min(mini, it.second);
                }
                //add diff(beauty) to sum
                sum += (maxi - mini);
            }
        }
        return sum;
    }
};