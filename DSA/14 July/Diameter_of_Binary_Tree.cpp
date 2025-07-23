class Solution {
public:
    int maxDiameter;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        depthFirstSearch(root);
        return maxDiameter;
    }

    int depthFirstSearch(TreeNode* node) {
        if (node == nullptr) return 0;  
        int leftDepth = depthFirstSearch(node->left);
        int rightDepth = depthFirstSearch(node->right);
        maxDiameter = max(maxDiameter, leftDepth + rightDepth);
        return 1 + max(leftDepth, rightDepth);
    }
};
