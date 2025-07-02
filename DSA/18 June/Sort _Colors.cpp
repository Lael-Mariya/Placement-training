// Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)
// Using brute force, count method for loops and swap, Time Complexity: O(2n)
// Dutch National Flag Algo, using 3-pointers, Time Complexity: O(n)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len=nums.size();
        int low =0,mid =0,high =len-1; 
        while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
            }
        }
    }
};
