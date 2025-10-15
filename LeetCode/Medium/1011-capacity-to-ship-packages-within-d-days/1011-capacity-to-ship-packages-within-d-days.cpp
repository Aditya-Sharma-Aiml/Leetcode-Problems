class Solution {
private:
    int findDays(vector<int>&wts , int cap){

        int day = 1 , load = 0; // first day

        for(int i=0 ; i<wts.size() ; i++){

            //if cross the capacity of ship
            if( (load + wts[i]) > cap) {
                //load on next day
                day += 1;
                load = wts[i];
            }
            else{

                //load on same day
                load += wts[i];
            }
        }
        return day;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {

        // may lowest possible capacity
        int low = *max_element(weights.begin(),weights.end());
        // highest possible capacity -> ship packages in a day
        int high = accumulate(weights.begin(),weights.end() , 0);

        while(low <= high){

            int mid = low + (high - low)/2;
            int tookDays = findDays(weights , mid);

            if(tookDays <= days) high = mid -1; // go for least => eliminate right
            else low = mid + 1; // not possible => eliminate left
        }
        return low;

    }
};