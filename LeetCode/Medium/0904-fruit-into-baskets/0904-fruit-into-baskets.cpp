class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // problem break down : maxLen subarray with at most 2 type numbers
        int n = fruits.size();
        int l = 0, r = 0;
        int maxLen = 0; // maxFruits

        unordered_map<int, int>basket;

        while(r < n){

            basket[fruits[r]]++;

            if(basket.size() > 2){ // making valid segment

                basket[fruits[l]]--;

                if(basket[fruits[l]] == 0) basket.erase(fruits[l]);
                l++;
            }

            if(basket.size() <= 2){ // valid segment
                maxLen = max(maxLen, r-l+1);
            }

            r++;

        }
        return maxLen;// max fruit

    }
};