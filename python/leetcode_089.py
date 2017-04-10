class Solution(object):
    def grayCode(self,n):
        result=[0]
        cur=1
        for i in range(n):
            result+=[x+cur for x in reversed(result)]
            cur<<=1
        return result

class Solution(object):
    def grayCode(self,n):
        if n==0:
            return [0]
        if n==1:
            return [0,1]
        m=2**(n-1)
        gray=self.grayCode(n-1)
        for item in gray[::-1]:
            gray.append(m+item)
        return gray

class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        m=2**n-1
        gray=list({0})
        cur=1
        for i in range(m):
            gray.append(cur^(cur>>1))
            cur+=1
        return gray