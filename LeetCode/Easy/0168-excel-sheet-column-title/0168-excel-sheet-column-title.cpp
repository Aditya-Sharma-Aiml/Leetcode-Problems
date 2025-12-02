class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title = "";
        while(columnNumber > 0){
            columnNumber--; // make 0 - based
            int rem = columnNumber % 26;
            title += 'A' + rem;
            columnNumber /= 26;
        }
        reverse(title.begin(),title.end());
        return title;
    }
};