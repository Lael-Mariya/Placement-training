class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& grmpy, int minWin) {
        int totalUnsat=0, total=0, windowUnsat=0, maxSat=0, n=cust.size();
        for(int i=0;i<n;++i) {
            totalUnsat+=cust[i]*grmpy[i];
            total+=cust[i];
        }
        for(int i=0;i<n;++i) {
            windowUnsat+=cust[i]*grmpy[i];
            int start=i-minWin;
            if(start>=0) {
                maxSat=max(maxSat,total-(totalUnsat-windowUnsat));
                windowUnsat-=cust[start]*grmpy[start];
            }
        }
        maxSat=max(maxSat,total-(totalUnsat-windowUnsat));
        return maxSat;
    }
};
