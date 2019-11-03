#include <climits>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_product=1;
        int pre_product=1;
        int succ_product=1;
        int first_neg=-1;
        int last_neg=-1;
        int res=INT_MIN;
        bool has_pos=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                if(first_neg==-1){
                    first_neg=i;
                }else{
                    succ_product=1;
                }
                last_neg=i;
                curr_product*=nums[i];
            }else if(nums[i]>0){
                if(!has_pos){
                    has_pos=true;
                }
                if(first_neg==-1){
                    pre_product*=nums[i];
                }else{
                    succ_product*=nums[i];
                }
                curr_product*=nums[i];
            }else{
                int cur_max=INT_MIN;
                if(curr_product>0){
                    if(first_neg==-1&&!has_pos){
                        cur_max=0;
                    }else{
                    cur_max=curr_product;
                    }
                }else{
                    if(last_neg==first_neg){
                        if(has_pos){
                            cur_max=max(succ_product,pre_product);
                        }else{
                            cur_max=0;
                        }
                    }else{
                        cur_max=max(curr_product/succ_product/nums[last_neg],curr_product/pre_product/nums[first_neg]);
                    }
                }
                has_pos=false;
                pre_product=1;
                succ_product=1;
                curr_product=1;
                first_neg=-1;
                last_neg=-1;
                res=max(cur_max,res);
            }
        }
        if(curr_product>0){
                if(first_neg==-1&&!has_pos){
                        res=max(res,0);
                }else{
                res=max(res,curr_product);
                }
            }else{
                if(last_neg==first_neg){
                    if(has_pos){
                        res=max(res,max(succ_product,pre_product));
                    }else{
                        res=max(nums[last_neg],res);
                    }
                }else{
                    res=max(res,max(curr_product/succ_product/nums[last_neg],curr_product/pre_product/nums[first_neg]));
                }
            }
        return res;
    }
};