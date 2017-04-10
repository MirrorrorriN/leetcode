class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board,0,0);
    }
private:
    bool dfs(vector<vector<char> >& board,int i,int j){
        if(i==9) return true;
        if(j==9) return dfs(board,i+1,0);
        if(board[i][j]!='.') return dfs(board,i,j+1);
        for(char c='1';c<='9';c++){
            if(check(board,i,j,c)){
                board[i][j]=c;
                if(dfs(board,i,j+1)) return true;
                board[i][j]='.';
            }
        }
        return false;
    }
    bool check(vector<vector<char> >& board,int i,int j,char c){
        for(int a=0;a<9;a++){
            if(board[a][j]==c) return false;
        }
        for(int b=0;b<9;b++){
            if(board[i][b]==c) return false;
        }
        int row=i/3,column=j/3;
        for(int a=row*3;a<row*3+3;a++)
            for(int b=column*3;b<column*3+3;b++){
                if(board[a][b]==c) return false;
            }
        return true;
    }
};