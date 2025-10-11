class Solution {
public:
    int findMax(vector<int>piles){
        // finding maximum bananas inn any piles
        int maxi = INT_MIN;
        for(auto bananas : piles){
            maxi = max(maxi , bananas);
        }
        return maxi;
    }
    
    long long  calculateTotalHours(vector<int>piles , int hourly){

        long long  totalHours = 0;

        for(auto bananas : piles){
            totalHours += ceil((double)bananas / (double)hourly); // ceil -> double
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1 , high = findMax(piles);
        
        while(low <= high ){

            int mid = low + (high - low)/2;
            long long  totalHours = calculateTotalHours(piles , mid);

            if(totalHours <= h) { //possible but  go for minimum rate(eliminate right)
                high = mid -1;
            }
            else{ // not possible so eliminate left
                low = mid + 1;
            }
            
        }
        return low;
    }
};