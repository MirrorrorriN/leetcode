#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	void sortColors(vector<int>& nums){
		int tmp,low=0,mid=0,high=nums.size()-1;
		while(mid<=high){
			if (nums[mid]==0){
				tmp=nums[mid];
				nums[mid]=nums[low];
				nums[low]=tmp;
				low++;
				mid++;
			}
			else if (nums[mid]==2){
				tmp=nums[mid];
				nums[mid]=nums[high];
				nums[high]=tmp;
				high--;
			}
			else{
				mid++;
			}
		}
	}
};

int main(int argc,char* argv[]){
	Solution *x=new Solution();
	vector<int> colors{1,2,0,0,1,0,2,1,2};
	x->sortColors(colors);
	for (auto it=colors.begin();it!=colors.end();++it){
		cout<<*it<<endl;
	}
	return 0;
}