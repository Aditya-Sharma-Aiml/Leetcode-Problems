class Solution {
public:
    // int countSet(int num){
    //     int count =0;
    //     while(num!=0){
    //         if(num&1) count++;
    //         num =num>>1;
    //     }
    //     return count;
    // }
    vector<int> countBits(int n) {
        // vector<int>ans(n+1,0);
        // for(int i=0 ; i<=n ; i++){
        //     ans[i] = countSet(i);
        // }
        // return ans;
        vector<int> ans(n+1, 0);
        for(int i = 1; i <= n; i++){
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;

    }
};
