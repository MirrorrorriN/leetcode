#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()==0){
            return 0;
        }
        int start=0;
        int end=height.size()-1;
        int res=0;
        while(start<end){
            res=max(res,(end-start)*min(start,end));
            if(height[start]<height[end]){
                start++;
            }else{
                end--;
            }
        }
        return res;
    }
};