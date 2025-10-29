class Solution {
public:
    bool isAllSet(int x){
        while(x>0){
            if((x&1)==0) {   
                return false;         
            }
           x = x>>1; 
        }
        return true;
    }
    int smallestNumber(int n) {
        int x = n;
        while(!isAllSet(x)){  
            x++;
        }
        return x;
    }
};