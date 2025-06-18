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
