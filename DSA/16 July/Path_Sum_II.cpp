class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;
        vector<int> currentPath;

        function<void(TreeNode*, int)> depthFirstSearch = 
            [&](TreeNode* node, int remainingSum) {
            if (!node) {
                return;
            }

            remainingSum -= node->val;
            currentPath.push_back(node->val);

            if (!node->left && !node->right && remainingSum == 0) {
                allPaths.push_back(currentPath);
            }

            depthFirstSearch(node->left, remainingSum);
            depthFirstSearch(node->right, remainingSum);
            
            currentPath.pop_back();
        };

        depthFirstSearch(root, targetSum);
        return allPaths;
    }
};
