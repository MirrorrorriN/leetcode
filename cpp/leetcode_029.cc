class Solution {
public:

    long long divide(long long dividend, long long divisor) {
        if (dividend==0) return 0;
        if (dividend==INT_MIN && divisor==-1) return INT_MAX;
        bool flag=dividend>0 ^ divisor>0;
        long long ans=0;
        dividend=abs(dividend);
        divisor=abs(divisor);
        
        while(dividend>=divisor){
            long long a=1,b=divisor;
            while((b<<1)<=dividend){
                a<<=1;
                b<<=1;
            }
            ans+=a;
            dividend-=b;
        }
        if(flag) ans=-ans;
        return ans;
    }
};
