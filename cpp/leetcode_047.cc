class Solution {
public:
    bool nextPermutation(vector<int>& nums) {
        int pos = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pos = i;
                break;
            }
        } 
        if (pos == -1) {
            return true;
        }
        int l = -1;
        for (int i = nums.size() - 1; i > pos; i--) {
            if (nums[i] > nums[pos]) {
                l = i;
                break;
            } 
        } 
        swap(nums[pos], nums[l]);
        reverse(nums.begin() + pos + 1, nums.end()); 
        return false;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res{};
        bool flag=false;
        while(!flag){
            res.push_back(nums);
            flag=nextPermutation(nums);
        }
        return res;
    }
    
};