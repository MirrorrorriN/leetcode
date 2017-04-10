class Solution {
    public:
    void nextPermutation(vector<int>& nums) {
        int pos = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pos = i;
                break;
            }
        } 
        if (pos == -1) {
            reverse(nums.begin(),nums.end());
            return;
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
    }
}; 