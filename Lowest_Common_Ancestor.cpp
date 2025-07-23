class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* firstNode, TreeNode* secondNode) {
        if (!root || root == firstNode || root == secondNode) {
            return root;
        }
        
        TreeNode* leftLCA = lowestCommonAncestor(root->left, firstNode, secondNode);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, firstNode, secondNode);
        
        if (leftLCA && rightLCA) {
            return root;
        }
        
        return leftLCA ? leftLCA : rightLCA;
    }
};
