class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int res=0;
        int n=triangle.size();
        if(n==0) return res;
        vector<int> cur(n,INT_MAX);
        cur[0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=i;j>=0;j--){
                if(j==i) cur[j]=cur[j-1]+triangle[i][j];
                else if(j==0) cur[j]=cur[j]+triangle[i][j];
                else cur[j]=min(cur[j],cur[j-1])+triangle[i][j];
            }
        }
        res=INT_MAX;
        for(int i=0;i<n;i++){
            if(cur[i]<res) res=cur[i];
        }
        return res;
    }
};