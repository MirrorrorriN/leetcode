class Solution(object):
    def getSum(self,a,b):
        def add(a,b):
            if (not a) or (not b):
                if a:
                    return a
                return b
            return add(a^b,(a&b)<<1)

        if a*b<0:
            if a>0:
                return self.getSum(b,a)
            if add(~a,1)==b:
                return 0
            elif add(~a,1)<b:
                return add(~add(add(~a,1),add(~b,1)),1)
        return add(a,b)
if __name__=="__main__":
    a=16
    b=-7
    x=Solution()
    ans=x.getSum(a,b)
    print ans
