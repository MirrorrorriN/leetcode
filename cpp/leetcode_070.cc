class Solution {
public:
    int climbStairs(int n) {
        int a=1,b=2;
        if (n==1) return 1;
        for (int i=3;i<=n;i++)
        {
            b+=a;
            a=b-a;
        }
        return b;
    }
};