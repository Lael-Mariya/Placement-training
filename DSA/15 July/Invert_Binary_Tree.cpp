class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        function<void(TreeNode*)> depthFirstSearch = [&](TreeNode* node) {
            if (!node) {
                return;
            }
            swap(node->left, node->right);
            depthFirstSearch(node->left);
            depthFirstSearch(node->right);
        };
        depthFirstSearch(root);
        return root;
    }
};
