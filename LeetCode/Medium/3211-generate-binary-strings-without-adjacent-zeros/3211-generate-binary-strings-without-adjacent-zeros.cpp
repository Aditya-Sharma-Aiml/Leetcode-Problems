class Solution {
private:
    void generate(vector<string> &result, string curr, int n){

        // base case 
        if(curr.length() == n){
            result.push_back(curr);
            return ;
        }

        // left recrsn for 0
        if  (curr.empty() || curr.back() != '0'){
            generate(result, curr + '0', n);
        }
        // right recrsn for 1
        generate(result , curr + '1', n);

    }
public:
    vector<string> validStrings(int n) {
        vector<string>result;
        generate(result, "", n);
        return result;
    }
};