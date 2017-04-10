class Solution(object):
    def myPow(self,x,n):
        if n==0:
            return 1
        if n>0 or n%2==0:
            t=self.myPow(x,n/2)
        else:
            t=self.myPow(x,n/2+1)
        if n%2==0:
            return t*t
        elif(n>0):
            return t*t*x
        else:
            return t*t*(1.0/x)
        