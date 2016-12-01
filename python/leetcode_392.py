class Solution(object):
    def isSubsequence(self,s,t):
        next=self.next_cal(t)
        
        return self.KMP(s,t,next)
    def next_cal(self,t):
        next=[-1]*len(t)
        for i in range(1,len(t)):
            j=next[i-1]
            while(t[j+1]!=t[i] and (j>=0)):
                j=next[j]
            if t[i]==t[j+1]:
                next[i]=j+1
            else:
                next[i]=-1
        return next
    def KMP(self,s,t,next):
        i,j=0,0
        while(i<len(s) and j<len(t)):
            if (s[i]==t[j]):
                i+=1
                j+=1
            else:
                if j==0:
                    i+=1
                else:
                    j=next[j-1]+1
            
        if j==len(t):
            return True
        return False

if __name__=="__main__":         
    t="axcaxba"
    s="axcaxcaxbagdc"
    x=Solution()
    ans=x.isSubsequence(s,t)
    print ans
