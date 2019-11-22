#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        if(k==0){
            return;
        }
        vector<int> temp;
        if(k>n/2){
            k=n-k;
            for(int i=0;i<k;i++){
                temp.push_back(nums[i]);
            }
            for(int i=0;i<n-k-1;i++){
                nums[i]=nums[i+k];
            }
            for(int i=0;i<k;i++){
                nums[i+n-k-1]=temp[i];
            }
        }else{
            for(int i=n-k;i<n;i++){
                temp.push_back(nums[i]);
            }
            for(int i=n-k-1;i>=0;i--){
                nums[i+k]=nums[i];
            }
            for(int i=0;i<k;i++){
                nums[i]=temp[i];
            }
        }
    }
};