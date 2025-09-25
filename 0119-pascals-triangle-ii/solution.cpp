class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int>row;
        long long ans = 1;
        row.push_back(1);

        // nth row : n no. of element
        // ans = ans * ((row-col)/col)
        
        int nthRow = rowIndex+1;
        for(int c = 1 ; c<nthRow ;c++){

            ans *= nthRow-c;
            ans /= c;
            row.push_back((int)ans);

        }
        return row;

        
    }
};
