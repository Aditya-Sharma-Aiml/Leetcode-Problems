class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.empty()) {
            return {};
        }
        int n = intervals.size();
        vector<vector<int>>ans;
        // sorting 
        sort (intervals.begin(),intervals.end());

        for(int i=0 ; i<n ; i++){
            // if the current interval does not lie in the last interval:
            if ( ans.empty() || intervals[i][0] > ans.back()[1] ){
                
                ans.push_back(intervals[i]);
            }

            // if the current interval does not lie in the last interval:
            else {
                
                ans.back()[1] = max( ans.back()[1] , intervals[i][1] );
            }
        }
        return ans;

    }
};
