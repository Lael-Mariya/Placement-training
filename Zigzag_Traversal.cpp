class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        
        bool isLeftToRight = true;
        
        while (!nodesQueue.empty()) {
            int levelSize = nodesQueue.size();
            vector<int> level(levelSize);
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
                
                int index = isLeftToRight ? i : (levelSize - 1 - i);
                level[index] = node->val;
                
                if (node->left) {
                    nodesQueue.push(node->left);
                }
                if (node->right) {
                    nodesQueue.push(node->right);
                }
            }
            
            result.push_back(level);
            isLeftToRight = !isLeftToRight;
        }
        
        return result;
    }
};
