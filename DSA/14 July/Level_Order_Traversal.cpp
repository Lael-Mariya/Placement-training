class Solution {
public:
    vector<std::vector<int>> levelOrder(TreeNode* root) {
    vector<std::vector<int>> result;
        levelOrderRecursive(root, 0, result);
        return result;
    }

private:

    void levelOrderRecursive(TreeNode* node, int level, std::vector<std::vector<int>>& result) {
        if (node == nullptr) {
            return;
        }

        if (result.size() <= level) {
            result.push_back({});
        }
        result[level].push_back(node->val);
        levelOrderRecursive(node->left, level + 1, result);
        levelOrderRecursive(node->right, level + 1, result);
    }
};
