class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();

        if(n&1) return {};

        unordered_map<int,int>mp;

        vector<int>org = {};

        sort(changed.begin(), changed.end());

        for(int x : changed){
            mp[x]++;
        }
        for(int num : changed){

            int twice = num * 2;
            if (mp[num] == 0) continue;

            if (mp.find(twice) == mp.end() || mp[twice] == 0) 
                return {};
            org.push_back(num);
            mp[num]--;
            mp[twice]--;
            
        }
        return org;
    }
};