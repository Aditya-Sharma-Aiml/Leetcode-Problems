class Solution {
public:
    bool isPossible(vector<int>bloomDay, int day, int m, int k){

        int count = 0, noOfBouquets = 0;
        for(int i = 0 ; i < bloomDay.size() ; i++){
            
            if (bloomDay[i] <= day) count ++;
            else{
                // first take out bouquets
                noOfBouquets += (count / k);
                count = 0;
            }
        }
        noOfBouquets += (count/k); // for last possible 
        return noOfBouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        long long val  = m*1LL * k*1LL;
        int n = bloomDay.size();

        if(val > n) return -1 ; // impossible case
        int mini = *min_element(bloomDay.begin(),bloomDay.end());
        int maxi = *max_element(bloomDay.begin(),bloomDay.end());

        int low = mini , high = maxi ;
        while(low <= high){

            int mid = low + (high - low)/2;
            
            if (isPossible(bloomDay, mid, m, k)) high = mid -1;
            else low = mid + 1;
        }
        return low;
    }
};