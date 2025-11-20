class Solution {
public:
    int maximumWealth(vector<vector<int>>& acc) {
        // int m = acc.size();
        // int n = acc[0].size();
        int w = 0;
        // for(int i=0; i<m ; i++){
        //     int sum = 0;
        //     for(int j=0 ; j<n ;j++){
        //         sum+= acc[i][j];
        //     }
        //     w = max(w,sum);

        // }
        for(auto &customer : acc){
            w = max(w, accumulate(customer.begin(), customer.end(), 0));
        }
        return w;
    }
};