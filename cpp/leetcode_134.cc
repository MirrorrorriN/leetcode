class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int n=gas.size();
    	int sum=0,start=0;
    	if(n==1 && gas[0]>=cost[0]) return 0;
        for(int i=0;i<2*n-1;i++){
        	int x=i%n;
        	
        	sum+=gas[x]-cost[x];
        	while(sum<0 && start<n){
        		sum+=cost[start]-gas[start];
        		start=start+1;
        	}
        	if(start==n) return -1;
        	if(i-start==n-1){
        		return start;
        	}
        }
        return -1;
    }
};