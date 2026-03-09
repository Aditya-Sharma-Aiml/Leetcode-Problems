class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char>st;

        for(int i=0; i<num.size(); i++){ // case 0

            char currDigit = num[i];

            while(!st.empty() && k > 0 && st.top() > currDigit){
                st.pop();
                k--;
            }
            st.push(currDigit);
        }
        //case 1 : k == n or still left
        while(!st.empty() && k >0){
            st.pop();
            k--;
        }

        if(st.empty()) return "0"; 

        string ans = "";

        while(!st.empty()){ // store in reversal order

            ans.push_back(st.top());
            st.pop();
        }

        // case 2: remove leading zeros
        while(!ans.empty() && ans.back() == '0') ans.pop_back();

        if(ans.empty()) return "0";

        reverse(begin(ans), end(ans)); // actual ans

        return ans;

    }
};