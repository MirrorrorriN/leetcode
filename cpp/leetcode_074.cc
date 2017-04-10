class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int m=matrix.size();
        int start=0,end=matrix.size()-1;
        int n=matrix[0].size();
        if(n==0) return false;
        while(start<m&&matrix[start][n-1]<target){
            start++;
        }
        while(end>=0&&matrix[end][0]>target){
            end--;
        }
        if(start==m||end==-1) return false;
        if(end<start) {
            if(matrix[start][0]==target||matrix[end][n-1]==target)
                return true;
            else return false;
        }
        int cur=start;
        start=0;
        end=n-1;
        int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            if(matrix[cur][mid]==target) return true;
            if(matrix[cur][mid]<target){
                start=mid+1;
            }
            if(matrix[cur][mid]>target){
                end=mid-1;
            }
        }
        return false;
    }
};