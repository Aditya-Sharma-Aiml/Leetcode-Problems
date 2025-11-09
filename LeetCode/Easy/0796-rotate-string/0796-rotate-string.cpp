class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n = s.length();
        int m = goal.length();

        if(n != m) return false;

        // concatinate to itself 
        // so that it contain all rotations as a substring
        string TwiceOfS = s + s;
        return TwiceOfS.find(goal) != string::npos;
    }
};