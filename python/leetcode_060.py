import math
class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        nums=[]
        for ch in range(n):
            nums.append(str(ch+1))
        fac=math.factorial(n-1)
        m=n
        t=k
        result=[]
        while (t>1):
            index,t=divmod((t-1),fac)
            t=t+1
            if m>1:
                m=m-1
                fac=fac/m
            #print nums[index]
            result.append(nums[index])
            del(nums[index])
        for ch in nums:
            result.append(ch)
        return ''.join(result)
if __name__=="__main__":
    n=4
    k=23
    x=Solution()
    ans=x.getPermutation(n,k)
    print ans
