class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        m = len (matrix)
        if m==0:
            return
        n = len (matrix[0])
        last_row = -1
        for i in range(m):
            for j in range(n):
                if matrix[i][j]==0:
                    last_row=i
                    break
        if last_row == -1:
            return
        for i in range(last_row):
            flag=False
            for j in range(n):
                if matrix[i][j]==0:
                    matrix[last_row][j]=0
                    flag=True
            if flag:
                for j in range(n):
                    matrix[i][j]=0
        for j in range(n):
            if matrix[last_row][j]==0:
                for i in range(m):
                    matrix[i][j]=0
        for j in range(n):
            matrix[last_row][j]=0
        return