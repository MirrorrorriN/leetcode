class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] ans=new int[2];
        int l=numbers.length;
        int i=0;
        while(i<l-1&&numbers[i]<=target){
            int j=i+1;
            while(j<l&&numbers[i]+numbers[j]<=target){
                if(numbers[i]+numbers[j]==target){
                    ans[0]=i+1;
                    ans[1]=j+1;
                    return ans;
                }
                j++;
            }
            i++;
        }
        return ans;
    }
}