import java.util.Scanner;
class Solution {
    public int numSquares(int n) {
        // 四方定理推论 满足(4^a)*(8b+7)=n(a,b为自然数)的数该题的解为4
        int a=1;
        int b=0;
        int total=0;
        while(a*7<=n){
            b=0;
            total=a*7;
            while(total<n){
                b+=8;
                total=a*(b+7);
            }
            if(total==n){
                return 4;
            }
            a<<=2;
        }
        int tmp=(int)Math.sqrt(n);
        if(tmp*tmp==n){
            return 1;
        }
        for(int i=1;i<=tmp;i++){
            for(int j=i;j<=tmp;j++){
                if(i*i+j*j==n){
                    return 2;
                }
            }
        }
        return 3;
    }

    //DP解法
    public int numSquares1(int n) {
        int[] f=new int[n+1];
        f[0]=0;
        for(int i=1;i<=n;i++){
            int tmp=(int)Math.sqrt(n);
            f[i]=Integer.MAX_VALUE;
            for(int j=1;j<=tmp;j++){
                if(i<j*j){
                    break;
                }
                int cur=f[i-j*j]+1;
                if(cur<f[i]){
                    f[i]=cur;
                }
            }
        }
        return f[n];
    }
    public static void main(String[] args){
        Solution x=new Solution();
        Scanner sc = new Scanner(System.in); 
        System.out.println("请输入n："); 
        int n = sc.nextInt(); 
        System.out.println(x.numSquares(n));
        System.out.println(x.numSquares1(n));
    }
}
