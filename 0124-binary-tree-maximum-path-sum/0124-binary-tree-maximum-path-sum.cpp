/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        maxGain(root, maxsum);
        return maxsum;
    }

private:
    int maxGain(TreeNode* node, int &maxsum) {
        if (node == nullptr) return 0;
        int leftGain = max(maxGain(node->left, maxsum), 0);
        int rightGain = max(maxGain(node->right, maxsum), 0);
        int currentPathSum = node->val + leftGain + rightGain;
        maxsum = max(maxsum, currentPathSum);
        return node->val + max(leftGain, rightGain);
    }
};
