#include<iostream>
#include<vector>
using namespace std;
// 边界条件问题 mid+1=nums
//https://www.cnblogs.com/grandyang/p/4040438.html
class Solution {
public:
    int findMin(vector<int>& nums) {
        //当且仅当此情况里可能有mid+1>=nums.size();
        if(nums.size()==1){
            return nums[0];
        }
        return hepler(nums,0,nums.size()-1);
    }
    int hepler(vector<int> nums,int start,int end){
        if(start==end) return nums[start];
        if(nums[start]<nums[end]) return nums[start];
        if(nums[start]==nums[end]){
            while(start<end&&nums[start]==nums[end]){
                start++;
            }
            if(nums[start]==nums[end]){
                return nums[start];
            }
        }
        int mid=(start+end)/2;
        return min(hepler(nums,start,mid),
        hepler(nums,mid+1,end));
    }
};