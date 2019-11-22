// 待记录数学公式化推导 
// " "代表0 "A-Z" 1-26 reminder为0是特殊处理
#include<stack>
using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
        if(n<1){
            return "";
        }
        stack<char> s;
        while(n!=0){
            if(n%26==0){
                n=n/26-1;
                s.push('Z');
            }else{
                s.push(char(n%26+64));
                n=n/26;
            }
        }
        string res;
        while(!s.empty()){
            res+=s.top();
            s.pop();
        }
        return res;
    }
};