class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if(s1.length()+s2.length()!=s3.length()){
            return false;
        }
        final int M=s1.length();
        final int N=s2.length();
        boolean[][] arr=new boolean[M+1][];
        for(int i=0;i<=M;i++){
            arr[i]=new boolean[N+1];
        }
        // 默认值全为false
        arr[0][0]=true;
        for(int i=0;i<=M;i++){
            for(int j=0;j<=N;j++){
                if(i>0&&s3.charAt(i+j-1)==s1.charAt(i-1)&&arr[i-1][j]==true){
                    arr[i][j]=true;
                }else if(j>0&&s3.charAt(i+j-1)==s2.charAt(j-1)&&arr[i][j-1]==true){
                    arr[i][j]=true;
                }
            }
        }
        return arr[M][N];
    }
}