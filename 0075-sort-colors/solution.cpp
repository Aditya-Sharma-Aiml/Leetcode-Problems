class Solution {
public:
    void sortColors(vector<int>& arr) {

        // int cnt0{}, cnt1 = 0, cnt2 = 0;
        // int n= arr.size();

        // // count 0's , 1's ,2's
        // for(int i=0 ;i<n ;i++){
        //     if(arr[i]==0) cnt0++;
        //     else if(arr[i]==1) cnt1++;
        //     else cnt2++;
        // }

        // // manually change arr -> 0 upto cnt0
        // for(int i=0 ;i<cnt0 ;i++){
        //     arr[i]=0;
        // }

        // // manually change arr -> 1:  cnt0 se cnt1 tk
        // for(int i=cnt0 ;i<cnt0+cnt1 ;i++){
        //     arr[i]=1;
        // }

        // // manually change arr ->2:  cnt2 se n tk 
        // for(int i=cnt0+cnt1;i<n ;i++){
        //     arr[i]=2;
        // }

        //dutch national flag algorithm:
        int n = arr.size();
        int low = 0 , mid = 0 , high = n-1;

        while(mid<=high){

            if(arr[mid]==0){
                swap(arr[mid],arr[low]);
                low++;
                mid++;
            }

            else if(arr[mid]==1){
                mid++;
            }

            else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }
};
