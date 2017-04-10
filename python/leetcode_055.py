class Solution(object):
    def canJump(self, nums):
        n=len(nums)
        fetch=[0]*(n)
        fetch[0]=nums[0]
        for i in range(n-1):
            if fetch[i]>=i+1:
                fetch[i+1]=max(fetch[i],i+1+nums[i+1])
            else:
                return False
        return True

class Solution(object):
    def canJump(self, nums):
        n=len(nums)
        fetch=[0]*(n)
        fetch[0]=nums[0]
        for i in range(n-1):
            if fetch[i]<=i:
                return False
            else:
                fetch[i+1]=max(fetch[i],i+1+nums[i+1])
        return True