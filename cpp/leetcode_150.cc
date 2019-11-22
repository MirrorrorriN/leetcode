// evaluate-reverse-polish-notation
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||
            tokens[i]=="-"||
            tokens[i]=="*"||
            tokens[i]=="/"){
                if(s.size()<2){
                    // error;
                    return INT_MIN;
                }
                int b=s.top();
                s.pop();
                int a=s.top();
                s.pop();
                if(tokens[i]=="+"){
                    s.push(a+b);
                }else if(tokens[i]=="-"){
                    s.push(a-b);
                }else if(tokens[i]=="*"){
                    s.push(a*b);
                }else {
                    s.push(a/b);
                }
                
            }else{
                int curr=atoi(tokens[i].c_str());
                s.push(curr);
            }
        }
        if(s.size()==1){
            return s.top();
        }else{
            //error
            return INT_MIN;
        }
    }
};