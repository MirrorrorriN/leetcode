import sys
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        diff=sys.maxint
        nums.sort()
        n=len(nums)
        for i in range(n-2):
            if (i>0) and (nums[i]==nums[i-1]):
                continue
            left,right=i+1,n-1
            while(left<right):
                a=nums[i]+nums[left]+nums[right]
                cur=a-target
                if (cur==0):
                    return a
                if abs(cur)<diff:
                    diff=abs(cur)
                    closest=a
                if cur>0:
                    right-=1
                else:
                    left+=1
        return closest   
if __name__=="__main__":
    nums=[0,2,1,-3]
    target=1
    x=Solution()
    ans=x.threeSumClosest(nums,target)
    print ans
