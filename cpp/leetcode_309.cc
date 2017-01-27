/*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

    You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
    After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
    	if (prices.size()==0)
    		return 0;
    	vector<int> s0(prices.size(),0),s1(prices.size(),0),s2(prices.size(),0);
    	s1[0]=-prices[0];
    	for (int i=1;i<prices.size();i++)
    	{
    		s0[i]=max(s0[i-1],s2[i-1]);
    		s1[i]=max((s0[i-1]-prices[i]),s1[i-1]);
    		s2[i]=s1[i-1]+prices[i];
    	}
    	return max(s0[prices.size()-1],s2[prices.size()-1]);
    }
};

int main(int argc,char** argv)
{
	Solution* x=new Solution();
	vector<int> prices{3,2,6,5,0,3};
	cout<<x->maxProfit(prices)<<endl;
	return 0;
}
