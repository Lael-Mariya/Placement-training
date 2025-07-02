// You are given an array of prices where prices[i] is the price of a given stock on an ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. 
// If you cannot achieve any profit, return 0.
// O(n) Time Complexity
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        int max_pf=0, min_pr=INT_MAX;
        for(int i=0; i<len; i++){
            min_pr=min(min_pr,prices[i]);
            max_pf=max(max_pf,prices[i]-min_pr);
        }
        return max_pf;          
    }
};
// Using two-pointer method, buy and sell where we run conditional statement to check if prices[sell] is greater than prices[buy] then this day is the best to sellthe stock to maximize the profit
// or we update buy=sell
class Solution {
public:
    int maxProfit(vector<int>& prices){
        int buy=0;
        int sell=1;
        int maxProfit = 0;
        while (sell<prices.size()){
            if (prices[sell]>prices[buy]) {
                int profit=prices[sell]-prices[buy];
                maxProfit=max(maxProfit,profit);
            } else {
                buy=sell;
            }
            sell++;
        }
        return maxProfit;
    }
};
