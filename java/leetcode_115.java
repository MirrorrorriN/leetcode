import java.util.Scanner;

class Solution {
    public int numDistinct(String s, String t) {
        final int M=s.length();
        final int N=t.length();
        int[][] arr=new int[M+1][];
        for(int i=0;i<=M;i++){
            arr[i]=new int[N+1];
        }
        for(int i=0;i<=M;i++){
            arr[i][0]=1;
        }
        for(int i=1;i<=M;i++){
            for(int j=1;j<=N;j++){
                if(s.charAt(i-1)==t.charAt(j-1)){
                    arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
                }
                else{
                    arr[i][j]=arr[i-1][j];
                }
            }
        }
        return arr[M][N];
    }

    public static void main(String[] args){
        Solution x=new Solution();
        Scanner sc = new Scanner(System.in); 
        System.out.println("请输入n："); 
        String s= sc.nextLine(); 
        String t= sc.nextLine();
        System.out.println(x.numDistinct(s,t));

    }
}