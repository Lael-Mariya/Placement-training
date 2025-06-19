//O(n) Time Complexity, using 2-pointer method O(n^2)
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
