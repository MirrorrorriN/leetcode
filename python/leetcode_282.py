class Solution(object):
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        expr=[]
        self.target=target
        for i in range(1,len(num)+1):
            if (i==1) or (i>1 and num[0]!='0'):
                self.dfs(num[i:],num[:i],int(num[:i]),int(num[:i]),expr)
        return expr
    def dfs(self,num,temp,cur,last,expr):
        if not num:
            if cur==self.target:
                expr.append(temp)
            return
        for i in range(1,len(num)+1):
            val=num[:i]
            if (i==1) or (i>1 and num[0]!='0'):
                self.dfs(num[i:],temp+'+'+val,cur+int(val),int(val),expr)
                self.dfs(num[i:],temp+'-'+val,cur-int(val),-int(val),expr)
                self.dfs(num[i:],temp+'*'+val,cur-last+last*int(val),last*int(val),expr)
