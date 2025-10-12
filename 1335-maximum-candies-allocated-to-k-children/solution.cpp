class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1, high = *max_element(candies.begin(), candies.end());
        long long ans = 0;

        while (low <= high) {

            long long mid = low + (high - low) / 2;
            long long cnt = 0;

            for (auto cnd : candies)
                cnt += cnd / mid; // each pile can make (cnd / mid) children happy

            if (cnt >= k) {
                ans = mid;
                low = mid + 1; // try to increase
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};

