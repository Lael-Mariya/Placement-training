// recursive
class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        traverse(root, result);
        return result;
    }
private:
    void traverse(TreeNode* node, std::vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        traverse(node->left, result);
        result.push_back(node->val);
        traverse(node->right, result);
    }
};
// iterative
class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> s;
        TreeNode* current = root;

        while (current != nullptr || !s.empty()) {
          
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();

            result.push_back(current->val);
            current = current->right;
        }       
        return result;
    }
};
