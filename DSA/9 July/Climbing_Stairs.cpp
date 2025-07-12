class Solution {
public:
    int climbStairs(int n) {
        int prev=0;
        int curr=1;
        for(int i=0;i<n;++i) {
            int next=prev+curr;
            prev=curr;
            curr=next;
        }
        return curr;
    }
};
// recursive
class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return 1;
        if (n==2) return 2;
        
        return climbStairs(n-2) + climbStairs(n-1);
    }
};
