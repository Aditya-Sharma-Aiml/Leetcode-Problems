class Solution {
public:
    bool powOfTwo(int n){
        return (n>0 && (n&(n-1))==0);
    }
    int countPairs(vector<int>& deliciousness) {

        const int MOD = 1e9 + 7;
        unordered_map<int,long long> mp;
        long long ans = 0;

        for(int num : deliciousness){
            // check har possible power of two sum
            for(int p = 1; p <= (1 << 22); p <<= 1){

                int rem = p - num;
                if(mp.find(rem) != mp.end()){
                    ans = (ans + mp[rem]) % MOD;
                }

            }
            mp[num]++;
        }
        return ans ;
   
    }
};
