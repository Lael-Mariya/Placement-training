class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                if (--k == 0) {
                    return root->val;
                }
                root = root->right;
            }
        }
        return 0;
    }
};
