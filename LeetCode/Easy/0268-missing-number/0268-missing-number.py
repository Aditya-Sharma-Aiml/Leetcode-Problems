class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        Xor = 0
        for i,n in enumerate(nums):
            Xor ^= n ^ (i+1) 

        return Xor

        