#include<vector>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<=1){
            return 0;
        }
        int maxV=nums[0];
        int minV=nums[0];
        for(int i=0;i<nums.size();i++){
            maxV=max(maxV,nums[i]);
            minV=min(minV,nums[i]);
        }
        //统一向上取整 当(maxV-miv)%nums.size()时，多加一个桶，最后一个桶装maxV
        int len=(maxV-minV)/nums.size()+1;
        vector<vector<int> > buckets((maxV-minV)/len+1);
        for(int i=0;i<nums.size();i++){
            int pos=(nums[i]-minV)/len;
            if(buckets[pos].empty()){
                buckets[pos].resize(2);
                buckets[pos][0]=nums[i];
                buckets[pos][1]=nums[i];
            }else{
                if(nums[i]<buckets[pos][0]){
                    buckets[pos][0]=nums[i];
                }else if(nums[i]>buckets[pos][1]){
                    buckets[pos][1]=nums[i];
                }
            }
        }
        int res=0;
        int prev=0;
        for(int i=0;i<buckets.size();i++){
            if(buckets[i].empty()){
                continue;
            }
            res=max(res,buckets[i][0]-buckets[prev][1]);
            prev=i;
        }
        return res;
    }
};