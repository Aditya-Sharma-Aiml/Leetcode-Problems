class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int N = nums.size();
        stack<int>st;
        vector<int>NGE(N);

        for(int i = 2*N-1; i>=0; i--){ 
            // hypothetically double the array for circular array

            int idx = i%N; // valid index
            int currElement = nums[idx];

            while(!st.empty() && st.top() <= currElement) 
                st.pop();

            if(i<N){ // agar i, N ke andar hi h ai mtlb valid index me hai 
                NGE[i] = st.empty() ? -1 : st.top();
            }
            st.push(currElement);
        }
        return NGE;
    }
};