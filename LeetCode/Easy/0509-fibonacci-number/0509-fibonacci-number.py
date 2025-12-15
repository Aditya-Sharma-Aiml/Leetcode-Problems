class Solution(object):
    def fib(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n==0 or n==1:
            return n
        n1 , n3 = 0 , 0
        n2 = 1
        while(n>0):
            n3 = n1+n2
            n1 = n2
            n2 = n3
            n -=1
        return n1

        