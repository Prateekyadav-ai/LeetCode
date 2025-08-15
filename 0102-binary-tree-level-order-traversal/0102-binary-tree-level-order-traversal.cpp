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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Result vector to store the level order traversal
        vector<vector<int>> ans;
        
        // Base case: if the tree is empty
        if (root == nullptr) {
            return ans;
        }
        
        // Queue for BFS
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level
            vector<int> currentLevel; // Vector to store nodes of the current level
            
            // Process all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* front = q.front();
                q.pop();
                currentLevel.push_back(front->val);
                
                // Push the left child if it exists
                if (front->left != nullptr) {
                    q.push(front->left);
                }
                
                // Push the right child if it exists
                if (front->right != nullptr) {
                    q.push(front->right);
                }
            }
            
            // Add the current level to the answer
            ans.push_back(currentLevel);
        }
        
        return ans;
    }
};
