class Solution{
public:
    vector<vector<int>> permute(vector<int>& nums){
        int n=nums.size();
        vector<vector<int>> permutations;
        vector<int> current_permutation(n);
        vector<bool> visited(n,false);
        function<void(int)> dfs=[&](int depth){
            if(depth==n){
                permutations.emplace_back(current_permutation);
                return;
            }
            for(int i=0;i<n;++i){
                if(!visited[i]){
                    visited[i]=true;
                    current_permutation[depth]=nums[i];
                    dfs(depth+1);
                    visited[i]=false;
                }
            }
        };
        dfs(0);
        return permutations;
    }
};
