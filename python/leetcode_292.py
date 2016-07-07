class Solution(object):
    def canWinNim(self,n):
        if (n%4==0):
            return False
        else:
            return True
if __name__=='__main__':
    num=4
    x=Solution()
    ans=x.canWinNim(num)
    print ans
