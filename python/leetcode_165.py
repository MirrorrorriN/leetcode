class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1=version1.split('.')
        v2=version2.split('.')
        l1=len(v1)
        l2=len(v2)
        n=0
        l=min(l1,l2)
        while (n<l):
            if int(v1[n])<int(v2[n]):
                return -1
            if int(v1[n])>int(v2[n]):
                return 1
            n+=1
        if l1<l2:
            while(n<l2):
                if int(v2[n])!=0:
                    return -1
                n+=1
        if l1>l2:
            while(n<l1):
                if int(v1[n])!=0:
                    return 1
                n+=1                   
        return 0
if __name__=="__main__":
    version1="10.2.03.21.0.0"
    version2="10.2.03.21"
    x=Solution()
    ans=x.compareVersion(version1,version2)
    print ans
