class Solution {
public:
    string largestOddNumber(string num) {
        
        int index = -1;
        for(int j=num.length()-1 ; j>=0 ; j--){

            if((num[j]-'0') % 2 == 1){
                index = j;
                break;
            }
        }   
        return num.substr(0,index+1);
    }
};