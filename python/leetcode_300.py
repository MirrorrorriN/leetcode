class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp=[1]*len(nums);
        #pre=[-1]*len(s)
        opt=0
        #end=1
        for i in range(len(nums)):
            for j in range (i):
                if(nums[j]<nums[i])and(dp[i]<dp[j]+1):
                    dp[i]=dp[j]+1
                    #pre[i]=j
            if(opt<dp[i]):
                opt=dp[i]
                #end=i
        return opt