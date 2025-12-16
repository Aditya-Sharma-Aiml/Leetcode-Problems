class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        count = maxCount = 0
        while i<len(nums):
            if nums[i] == 1:
                count += 1
                maxCount = max(count , maxCount)
            else:
                count = 0
            i += 1
        return maxCount
        