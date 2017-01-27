#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int i=0,res=0;
    	int n=nums.size();
    	while (i<n)
    	{
    		int tmp;
    		tmp=i;
    		while(nums[i+1]==nums[tmp])
    		{
    			i++;
    		}
    		nums[res]=nums[tmp];
    		i++;
    		res++;
    	}
    	for (i=1;i<=n-res;i++)
    	{
    		//nums.pop_back();
    		nums.erase(nums.end()-1);
    	}        
    	return res;
    }
};

int main(int argc,char* argv[])
{
	vector<int> nums={1,1,3,3,6,7,7};
	Solution *x=new Solution();
	int res=x->removeDuplicates(nums);
	for (auto it=nums.begin();it!=nums.end();it++)
	{
		cout<<*it<<endl;
	}
	cout<<res<<endl;
	return 0;
}