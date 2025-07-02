// Given an array of integers arr[] and an integer target. Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.
// Time Complexity: O(nlogn)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len=nums.size();
        int low=0, high=len-1;
        vector<pair<int, int>> arr;    // {value, og index}
        for (int i=0; i<len; i++) {
            arr.push_back({nums[i],i});   // stores the elements in pairs with their og indices, to retrieve the og indices of the unsorted array as the array is sorted for further operation. 
        }  
        sort(arr.begin(), arr.end());     
        while (low<high){
            int sum=arr[low].first + arr[high].first; // .first gives value         
            if (sum>target){
                high--;
            }
            else if (sum<target){
                low++;
            }
            else{
                return {arr[low].second,arr[high].second};  // .second gives the og index
            }
        }     
        return {};
    }
};

