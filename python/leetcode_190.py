class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        result=0
        t=0
        while(n>0):
            bit=(n>>1<<1)^n
            result=(result<<1)+bit
            n=n>>1
            t=t+1
        for i in range(32-t):
            result=result<<1
        return result
if __name__=="__main__":
    n=43261596
    x=Solution()
    ans=x.reverseBits(n)
    print ans
