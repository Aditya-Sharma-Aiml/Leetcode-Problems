class Solution {
public:
    int minimumDeletions(string s) {

        int mini = 0;
        int countB = 0;

        for(char ch : s){

            if(ch=='b') countB++;

            else{
                mini = min(mini+1, countB); // minimum cost of b or a
            }
        }
        return mini;
    }
};