class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string,multiset <string> > ans;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            ans[temp].insert(strs[i]);
        }
        for(auto a:ans){
            vector<string> temp(a.second.begin(),a.second.end());
            res.push_back(temp);
        }
        return res;
    }
};