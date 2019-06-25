/*
 * @lc app=leetcode id=123 lang=java
 *
 * [123] Best Time to Buy and Sell Stock III
 */
class Solution {
    public int maxProfit(int[] prices) {
        int res=0,minPrice=Integer.MAX_VALUE,maxPrice=Integer.MIN_VALUE;
        final int N=prices.length;
        int[] leftProfit = new int[N];
        int[] rightProfit = new int[N];
        for(int i=0;i<N;i++){
            if(prices[i]>minPrice){
                leftProfit[i]=res=Math.max(res,prices[i]-minPrice);
            }else{
                minPrice=prices[i];
                leftProfit[i]=res;
            }
        }
        res=0;
        for(int i=N-1;i>=0;i--){
            if(prices[i]<=maxPrice){
                rightProfit[i]=res=Math.max(res,maxPrice-prices[i]);
            }else{
                maxPrice=prices[i];
                rightProfit[i]=res;
            }
        }
        res=0;
        for(int i=0;i<N;i++){
            res=Math.max(res,leftProfit[i]+rightProfit[i]);
        }
        return res;
    }
}