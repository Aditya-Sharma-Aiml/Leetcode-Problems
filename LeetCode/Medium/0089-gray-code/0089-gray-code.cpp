class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>gray;
        int size = 1<<n; // pow(2,n)

        // gray = i ^ (i >> 1)
        for(int i=0; i<size; i++){
            gray.push_back(i ^ ( i >> 1));
        }
        return gray;
    }
};