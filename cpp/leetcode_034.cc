class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int a = search(nums, target);
        int b = search(nums, target + 1) - 1;
        if (a < n&&nums[a] == target)
            return{ a,b };
        else
            return{ -1,-1 };
    }
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};