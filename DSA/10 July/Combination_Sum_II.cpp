class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        function<void(int, int)> dfs=[&](int currentIndex, int currentSum) {
            if (currentSum==0) {
                ans.emplace_back(temp);
                return;
            }
            if (currentIndex>=candidates.size() || currentSum<candidates[currentIndex]) {
                return;
            }
            for (int j=currentIndex; j<candidates.size(); ++j) {
                if (j>currentIndex && candidates[j]==candidates[j-1]) {
                    continue;
                }
                temp.emplace_back(candidates[j]);
                dfs(j+1, currentSum-candidates[j]);
                temp.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};
