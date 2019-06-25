class Solution {
    public int singleNumber(int[] nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int s=0;
            for(int j=0;j<nums.length;j++){
                s+=(nums[j]>>i)&1;
            }
            // ans+=(s%3)<<i;
            ans|=(s%3)<<i;
        }
        return ans;
    }
}