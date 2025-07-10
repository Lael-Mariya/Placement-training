// YUsing two-pointer approach, Time Complexity: O(nlogn + n^2)
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();      
        for (int i = 0; i < n - 2 && nums[i] <= 0; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])  // optimisation for checking repeated values
                continue;        
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) ++j;
                else if (sum > 0) --k;
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j - 1]) ++j; // optimisation for checking repeated values
                    while (j < k && nums[k] == nums[k + 1]) --k; // optimisation for checking repeated values
                }
            }
        }       
        return result;
    }
};
