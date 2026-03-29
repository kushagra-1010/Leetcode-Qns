class Solution {
public:
    int maxSum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (!node) return 0;

        int left = max(0, maxGain(node->left));
        int right = max(0, maxGain(node->right));

        int currentPath = node->val + left + right;

        maxSum = max(maxSum, currentPath);

        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};