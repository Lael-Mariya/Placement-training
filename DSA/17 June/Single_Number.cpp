// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one. You must implement a solution with a linear runtime complexity and use only constant extra space.
// Time Complexity: O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len= nums.size();
        int xr=0;
        for(int i=0;i<len; i++ ){
            xr=xr^nums[i];
        }
        return xr;
    }
};
