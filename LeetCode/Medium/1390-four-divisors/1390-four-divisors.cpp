class Solution {
private:
    vector<int> hasDivisors(int n){
        vector<int>divisors;

        for(int i=1 ; i*i<=n ; i++){

            if (n%i==0){
                divisors.push_back(i);
                if(i != n/i) divisors.push_back(n/i);
            }
            if (divisors.size() > 4) return divisors;
        }
        return divisors;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int divSum = 0;
        for(int num : nums){

            vector<int> totalDiv = hasDivisors(num);
        
            if (totalDiv.size()==4) {
                divSum+= accumulate(totalDiv.begin(),totalDiv.end(),0);
            }
        }
        return divSum;
    }
};