// Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.
// Time Complexity: O(n), where N=size of array+1.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len= nums.size();
        int xr1=0, xr2=0;
        for(int i=0; i<len; i++){
            xr1=xr1^nums[i];
            xr2=xr2^i;
        }
        xr2=xr2^len;
        return xr1^xr2;        
    }
};
