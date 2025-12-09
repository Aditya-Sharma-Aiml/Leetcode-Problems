class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n, vector<int>(n));
        int t=0,b=n-1,l=0,r=n-1,x=1;
        while(t<=b && l<=r){
            for(int i=l;i<=r;i++) a[t][i]=x++; t++;
            for(int i=t;i<=b;i++) a[i][r]=x++; r--;
            for(int i=r;i>=l;i--) a[b][i]=x++; b--;
            for(int i=b;i>=t;i--) a[i][l]=x++; l++;
        }
        return a;
    }
};
