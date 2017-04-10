class Solution(object):
    def isValidSudoku(self,board):
        center=[[1,1],[1,4],[1,7],[4,1],[4,4],[4,7],[7,1],[7,4],[7,7]]
        direc=[[-1,-1],[-1,0],[-1,1],[0,-1],[0,0],[0,1],[1,-1],[1,0],[1,1]]
        for i in range(9):
            dict={}
            for j in range(9):
                if board[i][j]!='.' and (board[i][j]) in dict:
                    return False
                if board[i][j]=='.':
                    continue
                else:
                    dict[board[i][j]]=1
        for i in range(9):
            dict={}
            for j in range(9):
                if board[j][i]!='.' and (board[j][i]) in dict:
                    return False
                if board[j][i]=='.':
                    continue
                else:
                    dict[board[j][i]]=1
        for i in range(9):
            dict={}
            for j in range(9):
                if (board[center[i][0]+direc[j][0]][center[i][1]+direc[j][1]])=='.':
                    continue;
                if (board[center[i][0]+direc[j][0]][center[i][1]+direc[j][1]]) in dict:
                    return False
                dict[board[center[i][0]+direc[j][0]][center[i][1]+direc[j][1]]]=1
        return True

        """
        :type board: List[List[str]]
        :rtype: bool
        """