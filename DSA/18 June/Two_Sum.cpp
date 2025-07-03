// Given an array of integers arr[] and an integer target. Return indices of the two numbers such that their sum is equal to the target.
// Time Complexity: O(n logn)
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
// Using Hash table
// Time Complexity: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for (int i=0; i<nums.size(); i++){
            int complement= target-nums[i];  
            if (mpp.find(complement)!=mpp.end()){ // find for the complement, if present then return indices
                return {mpp[complement],i};
            }
            mpp[nums[i]]=i; // not found so store the num (key) with value (index), because we will check if the complement is there not in the map later
        }
        return{};
       
    }
};
