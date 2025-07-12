class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        function<void(int)> n_subsets=[&](int i)->void {
            if(i==nums.size()) {
                ans.push_back(curr);
                return;
            }
            n_subsets(i+1);
            curr.push_back(nums[i]);
            n_subsets(i+1);
            curr.pop_back();
        };
        n_subsets(0);
        return ans;
    }
};
