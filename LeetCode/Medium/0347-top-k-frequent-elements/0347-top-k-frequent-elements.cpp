class Solution {
public:
    typedef pair<int,int>pairs;
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> count;
        for (auto num : nums) count[num]++;

        // Create vector of pairs
        vector<pairs> freq;
        
        for (auto &it : count) {
            freq.push_back({it.first, it.second});
        }
        auto comparator = [](pairs &p1, pairs &p2){
            return p1.second > p2.second;
        };
        sort(freq.begin(),freq.end(),comparator);

        vector<int>ans;
        int i=0;
        for(int i=0 ; i<freq.size() && i<k; i++){   
            ans.push_back(freq[i].first);
        }
        return ans;

    }
};