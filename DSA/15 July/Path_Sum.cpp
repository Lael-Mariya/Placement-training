class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        function<bool(TreeNode*, int)> dfs = [&](TreeNode* node, int sumSoFar) -> bool {
            if (!node) {
                return false;
            }
            
            sumSoFar += node->val;
            
            if (!node->left && !node->right && sumSoFar == targetSum) {
                return true;
            }
            
            return dfs(node->left, sumSoFar) || dfs(node->right, sumSoFar);
        };
        
        return dfs(root, 0);
    }
};
