#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    static bool comp (const string& a,const string& b) {
        return (a+b).compare(b+a)>0?true:false;
    }  
    string largestNumber(vector<int>& nums) {
        vector<string> str_list;
        for(int i=0;i<nums.size();i++){
            str_list.push_back(to_string(nums[i]));
        }
        sort(str_list.begin(),str_list.end(),comp);
        string res;
        for(int i=0;i<str_list.size();i++){
            res+=str_list[i];
        }
        if(!res.empty()&&res[0]=='0'){
            return "0";
        }
        return res;
    }
};