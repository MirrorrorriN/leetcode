#include <climits>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=INT_MIN;
        int product=1;
        int pos_product=1;
        int pre_first_neg=0;

        for(int i=0;i<nums.size();i++){
            product*=nums[i];
            res=max(res,max(nums[i],product));
            if(pre_first_neg!=0){
                res=max(res,product/pre_first_neg);
            }
            if(nums[i]<0){
                if(pre_first_neg==0){
                    pre_first_neg=product;
                }
                pos_product=1;
            }else if(nums[i]>0){
                pos_product*=nums[i];
                res=max(res,pos_product);
            }else{
                product=1;
                pos_product=1;
                pre_first_neg=0;
            }
        }
        return res;
    }
};