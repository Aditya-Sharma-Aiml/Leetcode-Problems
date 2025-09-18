class Solution {
public:
    int longestConsecutive(vector<int>& arr) {

        int n= arr.size();
        if(n==0) return 0;

        int longest = 1;
        unordered_set<int>uset;
        
        for(int i=0 ; i<n ;i++){ // O(N)
            uset.insert(arr[i]);
        }

        for(auto it : uset){ // O(2N) not N^2

            // just previous consecutive number not exist mean here to start
            if(uset.find(it-1)==uset.end()){

                int count = 1;
                int x = it;

                // go forward in numbers until you didn't found next one 
                while(uset.find(x+1)!=uset.end()){  
                    count++;
                    x++;
                }

                longest = max(longest , count);

            }
        }

        return longest;


    }
};
