import math
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dic={}
        n=len(nums)
        for num in nums:
            if num in dic:
                dic[num]+=1
            else:
                dic[num]=1
            if dic[num]>math.floor(n/2):
                return num
if __name__=="__main__":
    array=[1,2,1,1]
    x=Solution()
    ans=x.majorityElement(array)
    print ans
