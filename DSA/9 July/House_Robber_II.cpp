// recursive
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }

private:
    int robRange(vector<int>& nums, int start, int end) {
        if(start > end) return 0;
        return max(
            nums[start] + robRange(nums, start + 2, end),
            robRange(nums, start + 1, end)
        );
    }
};
