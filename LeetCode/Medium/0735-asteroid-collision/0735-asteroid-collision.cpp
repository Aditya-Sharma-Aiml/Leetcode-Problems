class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        vector<int>st;

        for(int i=0; i<n; i++){

            // case1: +ve
            if(asteroids[i] > 0) st.push_back(asteroids[i]);

            else{
            
                // case 2: -ve and compare -> remove 
                while(!st.empty() && 
                st.back() > 0 && st.back() < abs(asteroids[i])){
                    st.pop_back();
                }
                // case 3: equal -> ignore(automatically : i++) and remove
                if(!st.empty() && st.back() == abs(asteroids[i])){
                    st.pop_back();
                }
                //case 4: stack empty and back->-ve hai
                else if(st.empty() || st.back() < 0) st.push_back(asteroids[i]);

            }
        }
        return st;

    }
};