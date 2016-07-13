import collections
class Solution(object):
    def bfs(self,grid,i,j,m,n,char):
        dir=[[-1,0],[0,-1],[0,1],[1,0]]
        queue=collections.deque([[i,j]])
        grid[i][j]=char
        while(queue):
           t=queue.popleft()
           for i in range(4):
               x=t[0]+dir[i][0]
               y=t[1]+dir[i][1]
               if(x>=0)and(y>=0)and(x<m)and(y<n)and(grid[x][y]=="O"):
                   grid[x][y]=char
                   queue.append([x,y])
    def solve(self,board):
        m=len(board)
        if m==0:
            return
        n=len(board[0])
        for i in range(m):
            if board[i][0]=="O":
                self.bfs(board,i,0,m,n,"*")
            if board[i][n-1]=="O":
                self.bfs(board,i,n-1,m,n,"*"),
        for j in range(1,n-1):
            if board[0][j]=="O":
                self.bfs(board,0,j,m,n,"*")
            if board[m-1][j]=="O":
                self.bfs(board,m-1,j,m,n,"*")
        #print board
        for i in range(1,m-1):
            for j in range(1,n-1):
                if board[i][j]=="O":
                    self.bfs(board,i,j,m,n,"X")
        #print board

        for i in range(m):
            for j in range(n):
                if (board[i][j]=="*"):
                    board[i][j]="O"
       
        return
if __name__=="__main__":
    board=[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
    #board=[["x","x","x"],["x","o","x"],["x","x","x"]]
    x=Solution()
    x.solve(board)
    print board
