class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        search(nums,res,0);
        return res;
    }
    void search(vector<int>& nums,vector<vector<int> >& res,int start){
        if(start==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            search(nums,res,start+1);
            swap(nums[start],nums[i]);
        }
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        search(nums,res,0);
        return res;
    }
    void search(vector<int>& nums,vector<vector<int> >& res,int start){
        if(start==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            search(nums,res,start+1);
            swap(nums[start],nums[i]);
        }
    }
};