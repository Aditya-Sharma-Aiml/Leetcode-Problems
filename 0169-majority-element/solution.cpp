class Solution {
public:
    int majorityElement(vector<int>& arr) {

        // moore voting algorithm 
        int n = arr.size();
        int count = 0;
        int element;
        for(int i=0 ; i<n ; i++){

            if(count==0){
                element = arr[i];
                count = 1;
            }

            else if (arr[i]==element){
                count++;
            }

            else{
                count--;
            }
        }

        // // if we not sure that majority exist :
        // int temp_count = 0;
        // for(int i=0 ; i<n ; i++){
        //     if(arr[i]==element) temp_count++;
        // }
        // if (temp_count>(n/2)) return element ;
        // else return -1;

        return element;
        
    }
};
