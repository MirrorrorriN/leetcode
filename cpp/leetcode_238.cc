#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
    	
    	int n=nums.size();
    	vector<int> product(n,1);
    	int productBegin=1;
    	int productEnd=1;
    	for (int i=0;i<n;i++)
    	{
    		product[i] *= productBegin;
    		productBegin *= nums[i];
    		product[n-i-1] *= productEnd;
    		productEnd *= nums[n-i-1];
    	}
    	return product;
    }
};

int main(int argc,char** argv)
{
	vector<int> nums{4,11,9,7};
	Solution* x=new Solution();
	vector<int> product;
	product = x->productExceptSelf(nums);
	for (auto it=product.begin();it!=product.end();it++)
	{
		cout<<*it<<endl;
	}
	return 0;
}
