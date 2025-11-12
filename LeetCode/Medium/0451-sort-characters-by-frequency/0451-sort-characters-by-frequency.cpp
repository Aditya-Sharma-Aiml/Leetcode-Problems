class Solution {
public:
    typedef pair<char,int>pairs; // <char , count of char>
    string frequencySort(string s) {

        vector<pairs> pairArr(123);
        //count freq of chars
        for(char ch : s){
            int freq = pairArr[ch].second;
            pairArr[ch] = {ch, freq+1};
        }
        //custom comparator(lambda function)
        auto comparator = [&](pairs p1, pairs p2){
                                return p1.second > p2.second;
        };
        
        sort(begin(pairArr),end(pairArr) , comparator);

        // resultant string
        string result = "";
        for(int i=0 ; i<123 ; i++){
            //if char present in string
            if(pairArr[i].second > 0){

                char ch = pairArr[i].first;
                int freq = pairArr[i].second;
                
                string temp = string(freq, ch);
                
                result += temp;
            }
        }
        return result;
    }
};