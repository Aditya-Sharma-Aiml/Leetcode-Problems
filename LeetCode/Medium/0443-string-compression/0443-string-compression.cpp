class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();
        int indx = 0;

        for(int i=0 ; i<n ;){

            char current = chars[i];
            int count  = 0;

            while(i<n && chars[i]==current){
                count++;
                i++;
            }
            chars[indx++] = current;

            if (count > 1){

                string c = to_string(count);

                for(char &ch : c){
                    chars[indx++] = ch;
                }
            }
        }

        return indx; 
    }
};