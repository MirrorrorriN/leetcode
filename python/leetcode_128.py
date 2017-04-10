class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dic=set(nums)
        best=0
        for x in dic:
        	if x-1 not in dic:
        		n=x
        		while n+1 in dic:
        			n=n+1
        		best=max(best,n-x+1)
        return best