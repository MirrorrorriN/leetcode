#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if(numerator==0){
            return "0";
        }
        int flag=(numerator>0)^(denominator>0);
        if(flag==1){
            res+="-";
        }
        long n=labs(numerator);
        long d=labs(denominator);
        long remainder=n%d;
        res+=to_string(n/d);
        if(remainder==0){
            return res;
        }
        res+=".";
        unordered_map<long,int> m;
        while(remainder!=0){
            if(m.find(remainder)!=m.end()){
                res.insert(m[remainder],"(");
                res+=")";
                return res;
            }
            m[remainder]=res.size();
            remainder*=10;
            res+=to_string(remainder/d);
            remainder%=d;
        }
        return res;
    }
};