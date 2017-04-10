class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res=(nums.size()>0?1:0);
        for (int n:nums)
        {
            if (n>nums[res-1])
                nums[res++]=n; 
        }
        return res;
    }
};