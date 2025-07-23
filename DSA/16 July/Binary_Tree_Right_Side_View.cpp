class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        if (!root) {
            return rightView;
        }

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);

        while (!nodesQueue.empty()) {
            int levelSize = nodesQueue.size();
            rightView.push_back(nodesQueue.back()->val);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = nodesQueue.front();
                nodesQueue.pop();

                if (currentNode->left) {
                    nodesQueue.push(currentNode->left);
                }
                if (currentNode->right) {
                    nodesQueue.push(currentNode->right);
                }
            }
        }
        return rightView;
    }
};
