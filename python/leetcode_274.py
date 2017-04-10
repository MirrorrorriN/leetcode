class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        temp=sorted(citations,reverse=True)
        for i in xrange(len(temp)):
            if temp[i]==i+1:
                return i+1
            if (temp[i]>i+1) and (i+1==len(temp) or temp[i+1]<=i+1):
                return i+1
        return 0