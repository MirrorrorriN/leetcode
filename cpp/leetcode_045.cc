class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> count(n,INT_MAX);
        count[0]=0;
        int start=0,end=0,cur=0;
        while(end<n-1){
            int temp=end+1;
            for(int i=start;i<n&&i<=end;i++){
                temp=max(temp,i+nums[i]);
            }
            start=end+1;
            end=temp;
            cur+=1;
        }
        return  cur;
    }
};