// Maximum Subarray Sum
// Using Kadane's Algorithm, Time Complexity: O(n), Using brute force, Time Complexity: O(n^2)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum=INT_MIN;
        int curr_sum=0;
       for (int i=0; i<nums.size(); i++){
            curr_sum+=nums[i]; 
            max_sum= max(max_sum,curr_sum);
            if (curr_sum<0){  // if the current sum is -ve then ignore that and reset to 0
                curr_sum=0;
            }
        }
       return max_sum;
    }
};
