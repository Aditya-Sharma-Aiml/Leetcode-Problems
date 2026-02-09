class Solution {
public:
    int partition(vector<int>& nums, int l, int h) {

        int pivot = nums[l + (h - l) / 2];

        while (l <= h) {

            while (nums[l] < pivot) l++;
            while (nums[h] > pivot) h--;

            if (l <= h) {
                swap(nums[l], nums[h]);
                l++;
                h--;
            }
        }

        return l;
    }

    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();
        int target = n - k;

        int l = 0, h = n - 1;

        while (l < h) {

            int idx = partition(nums, l, h);

            if (target < idx) h = idx - 1;
            else l = idx;
        }

        return nums[target];
    }
};
