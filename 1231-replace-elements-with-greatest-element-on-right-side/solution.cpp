class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        // o(n^2)
        // for(int i =0 ;i<arr.size();i++){
        //     // int flag =1;
        //     int greatest = -1;
        //     for(int j=i+1 ;j<arr.size() ; j++){
        //         if(arr[j]>=greatest){
        //             greatest=arr[j];
        //         }
                
        //     }
        //     arr[i]=greatest;
        // }
        // arr[arr.size()-1]=-1;
        // return arr;

        // o(n)
        int n = arr.size();
        int greatest= -1;
        
        for(int i= n-1 ; i>=0 ;i--){    
            int temp = arr[i];
            arr[i]=greatest;
            if(temp > greatest){
                greatest = temp;
            }
           
        }
            
        return arr;
    }
};
