class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0,n=nums.size();
        if (nums[n-1]<target) return n;
        while(nums[i]<target && i<nums.size())
        {
           i++; 
        }
        return i;
    }
};