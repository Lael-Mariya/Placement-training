// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// Time Complexity: O(log n)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len=nums.size();
        int low=0, high=len-1;
        int ans=len;
        
        while(low<=high){
            int mid=(low+high)/2;
            if (nums[mid]>=target){ //eliminating the right part of the array as this is a sorted array
                ans=mid;
                high=mid-1;
            }
            else{
            low=mid+1;
        }
    }
        return ans;
    }
};
