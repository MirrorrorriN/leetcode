// A 00 T 11 G 01 C 10
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<int,int> sMap;
        map<char,int> cMap={{'A',0},{'T',3},{'G',1},{'C',2}};
        map<int,char> iMap={{0,'A'},{3,'T'},{1,'G'},{2,'C'}};
        vector<string> res;
        if(s.size()<=10){
            return res;
        }
        int cur=0;
        vector<int> temp;
        for(int i=s.size()-1;i>=0;i--){
            cur<<=2;
            cur+=cMap[s[i]];
            if(i<=s.size()-10){
                if(i<=s.size()-11){
                    // cur-=cMap[s[i+10]]<<20;
                    cur=cur&1048575;
                }
                if(sMap.find(cur)!=sMap.end()){
                    sMap[cur]+=1;
                    if(sMap[cur]==2){
                        temp.push_back(cur);
                    }
                }else{
                    sMap[cur]=1;
                }
            }
        }
        for(int i=0;i<temp.size();i++){
            string s="";
            for(int j=0;j<10;j++){
                s+=iMap[temp[i]-(temp[i]>>2<<2)];
                temp[i]>>=2;
            }
            res.push_back(s);
        }
        return res;
    }
};