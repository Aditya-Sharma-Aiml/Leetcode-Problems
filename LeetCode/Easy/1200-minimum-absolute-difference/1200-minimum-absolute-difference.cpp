class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        int minDiff = INT_MAX;

        sort(arr.begin(), arr.end());

        for(int i=1; i<arr.size(); i++){

            int diff = arr[i] - arr[i-1];
            if(diff < minDiff){
                minDiff = diff;
                ans.clear();
                ans.push_back({arr[i-1], arr[i]});
            }
            else if(diff == minDiff)
                ans.push_back({arr[i-1], arr[i]});
        }
        return ans;
    }
};