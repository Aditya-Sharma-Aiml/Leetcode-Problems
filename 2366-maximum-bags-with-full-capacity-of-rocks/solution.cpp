class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {

        int n = capacity.size();
        vector<int> need(n);

        // Calculate how many rocks each bag still needs
        for (int i = 0; i < n; i++)
            need[i] = capacity[i] - rocks[i];

        // Sort by smallest requirement first
        sort(need.begin(), need.end());

        int fullBags = 0;

        // Fill bags greedily
        for (int required : need) {
            if (required == 0) {
                fullBags++;
                continue;
            }
            if (additionalRocks >= required) {
                additionalRocks -= required;
                fullBags++;
            } else {
                break;
            }
        }

        return fullBags;
    }
};
