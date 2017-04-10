class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        len_nums = len(nums)
        nums += [nums[-1] - 1]
        for i in xrange(len_nums):
            if nums[i] > nums[i+1]:
                return i

class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        low,high = 0,len(nums)-1
        while low<=high:
            if low==high:
                return low
            mid = (low+high)/2
            if nums[mid]<nums[mid+1]:
                low=mid+1
            else:
                high=mid

class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        num = self.helper(nums)
        for i in xrange(len(nums)):
            if nums[i]==num:
                return i 

    def helper(self,nums):
        n=len(nums)/2
        if (len(nums)==1):
            return nums[0]
        return max(self.helper(nums[:n]),self.helper(nums[n:]))