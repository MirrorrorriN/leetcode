class Solution(object):
    def generateMatrix(self, n):
        matrix= [[0 for col in range(n)] for row in range(n)]
        num=0
        visited= [[0 for col in range(n)] for row in range(n)]
        flag=[1,1]
        t=1
        cor=[0,0]
        for i in range(n**2):
            num+=1
            x=cor[0]
            y=cor[1]
            matrix[x][y]=num
            visited[x][y]=1
            if (t==0):
                if (cor[0]+flag[0]<0) or (cor[0]+flag[0]>=n) or (visited[cor[0]+flag[0]][cor[1]]==1):
                    flag[t]=-flag[t]
                    t=1-t
            else:
                if (cor[1]+flag[1]<0) or (cor[1]+flag[1]>=n) or (visited[cor[0]][cor[1]+flag[1]]==1):
                    flag[t]=-flag[t]
                    t=1-t
            cor[t]=cor[t]+flag[t]
        return matrix